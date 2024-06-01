#include <any>
#include <string>
#include <string.h>
#include <stdio.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <list>
#include <algorithm>
#include <set>
#include <map>
#include <time.h>
#include <functional>
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include <mutex>


using namespace std;

static bool debugUI = false;

struct src_loc {
    string file_name;
    int start_line = -1;
    int end_line = -1;
    int first_sent_line = -1;
};

#define FOR_EACH_ITEM(l, block) for (auto &item : (l)) { block }
#define FOR_EACH_ITEM_OF_EACH_LIST(l, block) for(auto &item1:(l)) {for (auto &item2: (item1)) {block}}
#define FOR_EACH_EACH_ITEM(l, block) for (auto &item1 : (l)) {for (auto &item2 : (item1.second)){ block }}
#define FOR_EACH_EACH_EACH_ITEM(l, block) for (auto &item1 : (l)) {for (auto &item2 : (item1.second)){for (auto &item3 : (item2.second)){ block }}}
#define REMOVE_QUOTATION(str) (str).substr(1, (str).size() - 2)
#define SWAP_ELEMENT(L,I,J) {auto itemI = L[I]; L[I] = L[J]; L[J] = itemI;}
#define REPLACE_QUOTATION_MARKS(S) replace_all_distinct(S, "\"", "'")

string joinVector(const vector<string> &, const string &);

template<typename ItemType>
string joinVector(const vector<ItemType *> &strList, const string &sep, string (*itemToString)(const ItemType *item)) {
    if (strList.empty()) {
        return "";
    }
    if (strList.size() == 1) {
        return itemToString(strList.front());
    }
    string ret;
    for (auto &iter :strList) {
        ret += itemToString(iter);
        ret += sep;
    }
    for (char c : sep) {
        ret.pop_back();
    }
    return ret;
}

string joinList(const list<string> &, const string &);

string joinList(list<string> &, const string &, int startPos, int length);

string joinList(list<pair<string, string>> &, const string &);

string joinList(const list<string> &strList, const string &sep, string (*itemModifier)(const string &item));

void splitStr(const string &listInStr, const string &sep, list<string> &ret);

string firstTextForQualifiedName(const string &qualifiedName);

string exceptLastTextWithoutSep(const string &text, const string &sepText);

string exceptLastTextForQualifiedName(const string &qualifiedName);

string exceptFirstTextWithoutSep(const string &text, const string &sepText);

string firstTextForTextSeparatedText(string text, const string &sepText);

string lastTextForQualifiedName(const string &qualifiedName);

string exceptFirstTextForQualifiedName(const string &qualifiedName);

string exceptFirstTextWithoutDotForQualifiedName(const string &qualifiedName);

bool empty(const list<string> &l);

string replace_all_distinct(string str, const string &old_value, const string &new_value);

string replace_first(string str, const string &old_value, const string &new_value);

string joinWithADot(const string &typeKey, const string &fileName);

template<typename ValueType>
void makeSureKeyExist(const string &key, map<string, ValueType> &infos) {
    if (infos.count(key) == 0) {
        ValueType info;
        infos[key] = info;
    }
}

template<typename T>
void copySet(const set<T> &src, set<T> &target) {
    target.clear();
    for (const auto &s : src) {
        target.insert(s);
    }
}

template<typename T>
void copyList(const list<T> &src, list<T> &target) {
    target.clear();
    for (const auto &l:src) {
        target.emplace_back(l);
    }
}

template<typename T>
void insertMapOfSet(map<string, set<T>> &m, const string &key, const T &value) {
    makeSureKeyExist(key, m);
    m.at(key).insert(value);
}

template<typename T>
void insertMapOfList(map<string, list<T>> &m, const string &key, const T &value) {
    makeSureKeyExist(key, m);
    m.at(key).emplace_back(value);
}

template<typename T>
void insertMapOfMap(map<string, map<string, T>> &m, const string &k1, const string &k2, const T &value) {
    makeSureKeyExist(k1, m);
    m[k1][k2] = value;
}

void easyPrint(int i);

void easyPrint(float i);

void easyPrint(const string &s);

void easyPrint(const string &s1, const string &s2);

void easyPrint(const string &s1, const string &s2, const string &s3);

bool endsWith(const string &s, const string &ends);

template<typename T>
static void saveToFile(T &dataToBeSaved, string (*saveFunc)(T &), string &saveFilePath) {
    FILE *fp = fopen(saveFilePath.data(), "w+");
    fprintf(fp, "%s", saveFunc(dataToBeSaved).data());
    fclose(fp);
}

template<typename T>
int indexOfVector(vector<T> &vec, const T &value) {
    for (int i = 0; i < vec.size(); ++i) {
        if (vec[i] == value) {
            return i;
        }
    }
    return -1;
}

template<typename T>
int indexOfList(list<T> &list_, const T &value) {
    int index = 0;
    for (auto &v:list_) {
        if (v == value) {
            return index;
        }
        index++;
    }
    return -1;
}

template<typename T, typename V>
bool pairTester(const pair<T, V> &underTest, const V &testerValue) {
    return underTest.second == testerValue;
}

template<typename T>
bool isInList(list<T> &list_, const T &value) {
    return indexOfList(list_, value) > -1;
}

// todo make base always 0
template<typename T>
T getFromList(list<T> &list_, int index, int base = 0) {
    int idx = base;
    for (auto &value:list_) {
        if (idx == index) {
            return value;
        }
        idx++;
    }
    T notFoundValue;
    return notFoundValue;
}

template<typename T, typename V>
pair<T, bool> getFromList(list<T> &list_, V &valueToFind, bool(*tester)(const T &underTest, const V &testerValue)) {
    for (auto &v:list_) {
        if (tester(v, valueToFind)) {
            return pair<T, bool>(v, true);
        }
    }
    T notFoundValue;
    return pair<T, bool>(notFoundValue, false);
}


template<typename T>
void extendList(list<T> &targetList, list<T> &srcList) {
    for (auto &l:srcList) {
        targetList.emplace_back(l);
    }
}

template<typename T>
void extendList(list<T> &targetList, set<T> &srcList) {
    for (auto &l:srcList) {
        targetList.emplace_back(l);
    }
}

template<typename K, typename V>
void convertTwoList2Map(const list<K> &klist, const list<V> &vlist, map<K, V> &retMap) {
    auto kiter = klist.begin();
    auto viter = vlist.begin();
    for (; kiter != klist.end();) {
        retMap[*kiter] = *viter;
        kiter++;
        viter++;
    }
}

template<typename K, typename V>
void reverseDictOfList(map<K, list<V>> &d, map<V, list<K>> &reverseD) {
    for (auto &dI:d) {
        for (auto &v:dI.second) {
            if (reverseD.template count(v) == 0) {
                reverseD[v] = list<K>();
            }
            reverseD.at(v).emplace_back(dI.first);
        }
    }
}

template<typename K, typename V>
list<K> &extractFirstFromPair(list<pair<K, V>> &p, list<K> &l) {
    for (pair<K, V> &i : p) {
        l.emplace_back(i.first);
    }
    return l;
}

template<typename ItemType>
class PooledItem {
public:
    thread_local static list<ItemType *> itemsInPool;

    static ItemType *getInstance();

    static void returnToPool(ItemType *ret);

    virtual void reset();
};


template<typename ItemType>
thread_local list<ItemType *> PooledItem<ItemType>::itemsInPool;

template<typename ItemType>
ItemType *PooledItem<ItemType>::getInstance() {
    ItemType *ret;
    if (itemsInPool.empty()) {
        ret = new ItemType();
    } else {
        ret = itemsInPool.front();
        itemsInPool.pop_front();
    }
    ret->reset();
    return ret;
}

template<typename ItemType>
void PooledItem<ItemType>::returnToPool(ItemType *ret) {
    itemsInPool.emplace_back(ret);
}

template<typename ItemType>
void PooledItem<ItemType>::reset() {

}

bool comparatorOfPair(const pair<string, int> &o1, const pair<string, int> &o2);

void mem_usage(double &vm_usage, double &resident_set);

void saveListLineByLine(list<string> &l, char *filePath);

void readListLineByLine(char *filePath, list<string> &l);

void printTime(const string &s, clock_t &startTime, clock_t &endTime);

string getArrayPostFix(int dim);
