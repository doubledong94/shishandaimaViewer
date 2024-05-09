//
// Created by ydd on 10/25/23.
//

#ifndef JPARSER_THREADPOOL_H
#define JPARSER_THREADPOOL_H


#include <functional>
#include <memory>

class ThreadPool {

public:
    explicit ThreadPool(unsigned int threadCount = 1);

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool(const ThreadPool&&) = delete;
    ThreadPool operator=(const ThreadPool&) = delete;

    void submit(const std::function<void()>& f);

    void clearTaskList();

    void onThreadEnd(const std::function<void()>& f);

    bool empty();

    void wait();

    ~ThreadPool();

private:
    struct Impl;
    std::unique_ptr<Impl> pimpl_;
};

#endif //JPARSER_THREADPOOL_H
