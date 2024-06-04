#include <unistd.h>
#include "util.h"

int getInt(ifstream& f) {
    string countStr;
    std::getline(f, countStr);
    return stoi(countStr);
}

float getFloat(ifstream& f) {
    string countStr;
    std::getline(f, countStr);
    return stof(countStr);
}

string joinVector(const vector<string> &strList, const string &sep) {
    if (strList.empty()) {
        return "";
    }
    if (strList.size() == 1) {
        return strList.front();
    }
    string ret;
    for (auto &iter :strList) {
        ret += iter + sep;
    }
    ret = ret.substr(0, ret.length() - sep.size());
    return ret;
}

string joinList(const list<string> &strList, const string &sep) {
    if (strList.empty()) {
        return "";
    }
    if (strList.size() == 1) {
        return strList.front();
    }
    string ret;
    for (auto &iter :strList) {
        ret += iter + sep;
    }
    ret = ret.substr(0, ret.length() - sep.size());
    return ret;
}

string joinList(list<string> &strList, const string &sep, int startPos, int length) {
    auto iter = strList.begin();
    int i = 0;
    for (; i < startPos; i++) {
        iter++;
    }
    string ret;
    for (; i < startPos + length and i < strList.size(); i++) {
        ret += (*iter) + sep;
        iter++;
    }
    if (!ret.empty()) {
        ret = ret.substr(0, ret.length() - sep.size());
    }
    return ret;
}

string joinList(list<pair<string, string>> &pairList, const string &sep) {
    string ret;
    for (auto &iter:pairList) {
        ret += iter.second + sep;
    }
    ret = ret.substr(0, ret.length() - 1);
    return ret;
}

string joinList(const list<string> &strList, const string &sep, string (*itemModifier)(const string &item)) {
    string ret;
    for (auto &iter :strList) {
        ret += itemModifier(iter) + sep;
    }
    ret = ret.substr(0, ret.length() - sep.size());
    return ret;
}

void splitStr(const string &listInStr, const string &sep, list<string> &ret) {
    if (listInStr.find(sep) == string::npos) {
        ret.push_back(listInStr);
    } else {
        string firstPart = firstTextForTextSeparatedText(listInStr, sep);
        ret.push_back(firstPart);
        string secondPart = exceptFirstTextWithoutSep(listInStr, sep);
        splitStr(secondPart, sep, ret);
    }
}

string firstTextForQualifiedName(const string &qualifiedName) {
    return firstTextForTextSeparatedText(qualifiedName, ".");
}

string firstTextForTextSeparatedText(string text, const string &sepText) {
    size_t pos = text.find(sepText);
    if (pos == string::npos) {
        return text;
    } else {
        return text.substr(0, pos);
    }
}

string lastTextForQualifiedName(const string &qualifiedName) {
    std::size_t pos = qualifiedName.rfind('.');
    if (pos == string::npos) {
        return qualifiedName;
    } else {
        return qualifiedName.substr(pos + 1, qualifiedName.size() - pos - 1);
    }
}

string exceptLastTextWithoutSep(const string &text, const string &sepText) {
    size_t pos = text.rfind(sepText);
    if (pos == string::npos) {
        return "";
    } else {
        return text.substr(0, pos);
    }
}

string exceptLastTextForQualifiedName(const string &qualifiedName) {
    return exceptLastTextWithoutSep(qualifiedName, ".");
}

string exceptFirstTextWithoutSep(const string &text, const string &sepText) {
    size_t pos = text.find(sepText);
    if (pos == string::npos) {
        return "";
    } else {
        return text.substr(pos + sepText.size(), text.length() - pos);
    }
}

string exceptFirstTextWithoutDotForQualifiedName(const string &qualifiedName) {
    return exceptFirstTextWithoutSep(qualifiedName, ".");
}

bool empty(const list<string> &l) {
    return l.empty();
}

string exceptFirstTextForQualifiedName(const string &qualifiedName) {
    size_t pos = qualifiedName.find('.');
    if (pos == string::npos) {
        return "";
    } else {
        return qualifiedName.substr(pos, qualifiedName.length() - pos);
    }
}

string replace_all_distinct(string str, const string &old_value, const string &new_value) {
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != string::npos) {
            str.replace(pos, old_value.length(), new_value);
        } else {
            break;
        }
    }
    return str;
}

string replace_first(string str, const string &old_value, const string &new_value) {
    for (string::size_type pos(0); pos != string::npos; pos += new_value.length()) {
        if ((pos = str.find(old_value, pos)) != string::npos) {
            str.replace(pos, old_value.length(), new_value);
            break;
        }
    }
    return str;
}

string joinWithADot(const string &typeKey, const string &fieldName) {
    return typeKey + "." + fieldName;
}

void easyPrint(int i) {
    printf("%d\n", i);
}

void easyPrint(float f) {
    printf("%f\n", f);
}

void easyPrint(const string &s) {
    printf("%s\n", s.data());
}

void easyPrint(const string &s1, const string &s2) {
    printf("%s  %s\n", s1.data(), s2.data());
}

void easyPrint(const string &s1, const string &s2, const string &s3) {
    printf("%s %s %s\n", s1.data(), s2.data(), s3.data());
}

bool endsWith(const string &s, const string &ends) {
    return s.size() >= ends.size() && s.find(ends) == s.size() - ends.size();
}

bool comparatorOfPair(const pair<string, int> &o1, const pair<string, int> &o2) {
    return o1.second > o2.second;
}

void mem_usage(double &vm_usage, double &resident_set) {
    vm_usage = 0.0;
    resident_set = 0.0;
    ifstream stat_stream("/proc/self/stat", ios_base::in); //get info from proc directory
    //create some variables to get info
    string pid, comm, state, ppid, pgrp, session, tty_nr;
    string tpgid, flags, minflt, cminflt, majflt, cmajflt;
    string utime, stime, cutime, cstime, priority, nice;
    string O, itrealvalue, starttime;
    unsigned long vsize;
    long rss;
    stat_stream >> pid >> comm >> state >> ppid >> pgrp >> session >> tty_nr
                >> tpgid >> flags >> minflt >> cminflt >> majflt >> cmajflt
                >> utime >> stime >> cutime >> cstime >> priority >> nice
                >> O >> itrealvalue >> starttime >> vsize >> rss; // don't care about the rest
    stat_stream.close();
    long page_size_kb = sysconf(_SC_PAGE_SIZE) / 1024; // for x86-64 is configured to use 2MB pages
    vm_usage = vsize / 1024.0 / 1024.0;
    resident_set = rss * page_size_kb / 1024.0;
}

void saveListLineByLine(list<string> &l, char *filePath) {
    ofstream f(filePath);
    for (auto &s:l) {
        f << s << "\n";
    }
    f.close();
}

void readListLineByLine(char *filePath, list<string> &l) {
    ifstream f(filePath);
    string s;
    while (std::getline(f, s)) {
        l.push_back(s);
    }
}

void printTime(const string &s, clock_t &startTime, clock_t &endTime) {
    string parseTime = to_string((endTime - startTime) / 1000000.0f);
    printf("%s: %ss\n", s.data(), parseTime.data());
}

string getArrayPostFix(int dim) {
    string ret = "";
    for (int i = 0; i < dim; i++) {
        ret.push_back('[');
        ret.push_back(']');
    }
    return ret;
}
