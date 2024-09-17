#include "util/ThreadPool.h"

#include <atomic>
#include <condition_variable>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>

struct ThreadPool::Impl {

    explicit Impl(unsigned int threadCount)
            : done_(false), pendingTasks_(0) {

        threadCount = std::min(std::thread::hardware_concurrency(), std::max(1u, threadCount));
        try {
            for (unsigned i = 0; i < threadCount; ++i) {
                threads_.emplace_back(&Impl::worker_thread, this);
            }
        } catch (...) {
            done_ = true;
            throw;
        }
    }

    void wait() {

        std::unique_lock<std::mutex> lck(m_);
        cv_finished_.wait(lck, [this]() { return workQueue_.empty() && (pendingTasks_ == 0); });
    }

    void submit(std::function<void()> f) {

        std::unique_lock<std::mutex> lck(m_);
        workQueue_.emplace(std::move(f));
        lck.unlock();
        cvWorker_.notify_one();
    }

    bool empty() {
        return workQueue_.empty();
    }

    void clearTaskList() {
        std::unique_lock<std::mutex> lck(m_);
        while (not workQueue_.empty()) {
            workQueue_.pop();
        }
        lck.unlock();
    }

    ~Impl() noexcept {

        std::unique_lock<std::mutex> lck(m_);
        done_ = true;
        lck.unlock();
        cvWorker_.notify_all();

        for (auto &thread : threads_) {
            thread.join();
        }
    }

    std::function<void()> onEnd = nullptr;
private:
    bool done_;
    std::mutex m_;

    unsigned int pendingTasks_;

    std::vector<std::thread> threads_;
    std::queue<std::function<void()>> workQueue_;

    std::condition_variable cvWorker_;
    std::condition_variable cv_finished_;

    void worker_thread() {

        while (true) {

            std::unique_lock<std::mutex> lck(m_);

            // If no work is available, block the thread here
            cvWorker_.wait(lck, [this]() { return done_ || !workQueue_.empty(); });
            if (!workQueue_.empty()) {

                ++pendingTasks_;

                auto task = std::move(workQueue_.front());
                workQueue_.pop();

                lck.unlock();

                // Run work function outside mutex lock context
                task();

                lck.lock();
                --pendingTasks_;
                lck.unlock();

                cv_finished_.notify_one();

            } else if (done_) {
                if(onEnd!=nullptr){
                    onEnd();
                }

                break;
            }
        }
    }
};

ThreadPool::ThreadPool(unsigned int threadCount)
        : pimpl_(std::make_unique<Impl>(threadCount)) {}

void ThreadPool::submit(const std::function<void()> &f) {

    pimpl_->submit(f);
}

void ThreadPool::clearTaskList() {
    pimpl_->clearTaskList();
}

void ThreadPool::onThreadEnd(const std::function<void()>& f) {
    pimpl_->onEnd = f;
}

bool ThreadPool::empty() {
    return pimpl_->empty();
}

void ThreadPool::wait() {

    pimpl_->wait();
}

ThreadPool::~ThreadPool() = default;
