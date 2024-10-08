#include "util/util.h"
#include "SWI-cpp2.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "addressableInfo/AddressableInfo.h"
#include "file/FileManager.h"
#include "prolog/PrologConstructor.h"
#include "prolog/PrologWrapper.h"
#include "error/ErrorManager.h"

PlEngine* PrologWrapper::e = NULL;

ofstream debug_prolog_file;

bool PrologWrapper::init() {
    debug_prolog_file.open(FileManager::baseFolder + "debug_prolog.pl");
    debug_prolog_file << (":-discontiguous resolve/2.") << "\n";
    debug_prolog_file << (":-discontiguous resolveRuntime/6.") << "\n";
    debug_prolog_file << (":-discontiguous forwardFa/7.") << "\n";
    debug_prolog_file << (":-discontiguous backwardFa/7.") << "\n";
    debug_prolog_file << (":-discontiguous forwardFa/8.") << "\n";
    debug_prolog_file << (":-discontiguous backwardFa/8.") << "\n";
    debug_prolog_file << (":-discontiguous forwardFa/9.") << "\n";
    debug_prolog_file << (":-discontiguous backwardFa/9.") << "\n";
    e = new PlEngine("");
    bool loaded = true;
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(baseRuleFile));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(typeKey2filePath));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(package2typeKeys));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(typeKey2subTypeKeys));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(override));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(MethodUseMethods));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(MethodUseFields));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Methods));
    loaded &= loadFileIfExist(FileManager::GLOBAL_PL_FILE_PATH(TypeKey2Fields));
    return loaded;
}

Term* PrologWrapper::query(CompoundTerm* term) {
    PlTermv av(term->args.size());
    int outputIndex = 0;
    for (int i = 0; i < term->args.size(); ++i) {
        Term* arg = term->args[i];
        av[i].unify_term(*arg->toPlTerm());
        if (arg->termType == Term::TERM_TYPE_VAR) {
            outputIndex = i;
        }
    }
    try {
        PlQuery q(term->head->toString(), av);
        while (q.next_solution()) {
            PlTerm plT = av[outputIndex];
            return convertPlTermToTerm(&plT);
        }
    } catch (PlException& e) {
        easyPrint(e.as_string());
        exit(1);
    }
    return nullptr;
}

PlQuery* PrologWrapper::makeQuery(CompoundTerm* term, PlTermv*& result, int& outputIndex) {
    result = new PlTermv(term->args.size());
    for (int i = 0; i < term->args.size(); ++i) {
        Term* arg = term->args[i];
        (*result)[i].unify_term(*arg->toPlTerm());
        if (arg->termType == Term::TERM_TYPE_VAR) {
            outputIndex = i;
        }
    }
    try {
        return new PlQuery(term->head->toString(), (*result));
    } catch (PlException& e) {
        easyPrint(e.as_string());
        exit(1);
    }
    return nullptr;
}

void PrologWrapper::queryList(CompoundTerm* term, const std::function<void(vector<Term*>&)>& consumer) {
    vector<Term*> retList;
    PlTermv av(term->args.size());
    list<int> outputIndex;
    for (int i = 0; i < term->args.size(); ++i) {
        Term* arg = term->args[i];
        av[i].unify_term(*arg->toPlTerm());
        if (arg->termType == Term::TERM_TYPE_VAR) {
            outputIndex.push_back(i);
        }
    }
    try {
        PlQuery q(term->head->toString(), av);
        while (q.next_solution()) {
            retList.clear();
            for (int i : outputIndex) {
                PlTerm plT = av[i];
                retList.push_back(convertPlTermToTerm(&plT));
            }
            consumer(retList);
            for (auto& item : retList) {
                item->returnThisToPool();
            }
        }
        term->returnThisToPool();
    } catch (PlException& e) {
        easyPrint(e.as_string());
        exit(1);
    }
}

int PrologWrapper::queryCount(CompoundTerm* term) {
    PlTermv av(term->args.size());
    for (int i = 0; i < term->args.size(); ++i) {
        Term* arg = term->args[i];
        av[i].unify_term(*arg->toPlTerm());
    }
    try {
        PlQuery q(term->head->toString(), av);
        while (q.next_solution()) {
            PlTerm plT = av[1];
            return convertPlTermToTerm(&plT)->integer;
        }
    } catch (PlException& e) {
        easyPrint(e.as_string());
        exit(1);
    }
    return 0;
}

void PrologWrapper::declareFun(const string& functorName, int arity) {
    debug_prolog_file << ":-dynamic " << functorName << "/" << to_string(arity) << "." << "\n";
    debug_prolog_file.flush();
    PlCall("dynamic " + functorName + "/" + to_string(arity) + ".");
}

void PrologWrapper::addFact(const string& factStr) {
    debug_prolog_file << factStr << "." << "\n";
    debug_prolog_file.flush();
    PlCall("assertz(" + factStr + ").");
}

void PrologWrapper::retractSingleFact(const string& factStr) {
    PlCall("retract(" + factStr + ").");
}

string PrologWrapper::makeUnderScoreArguments(int arity) {
    string underScoreArguments;
    for (int i = 0; i < arity; i++) {
        underScoreArguments += "_,";
    }
    underScoreArguments = underScoreArguments.substr(0, underScoreArguments.length() - 1);
    return underScoreArguments;
}

void PrologWrapper::retractAllFact(const string& functorName, int arity) {
    if (arity > 0) {
        // debug_prolog_file << ("retractall(" + functorName + "(" + makeUnderScoreArguments(arity) + ")).") << "\n";
        // debug_prolog_file.flush();
        PlCall("retractall(" + functorName + "(" + makeUnderScoreArguments(arity) + ")).");
    }
}

void PrologWrapper::addRule(const string& ruleStr) {
    debug_prolog_file << ruleStr << "." << "\n";
    debug_prolog_file.flush();
    PlCall("assertz((" + ruleStr + ")).");
}

void PrologWrapper::retractSingleRule(const string& ruleStr) {
    PlCall("retract((" + ruleStr + ")).");
}

void PrologWrapper::retractAllRule(const string& header, int arity) {
    PlCall("retractRules(" + header + "(" + makeUnderScoreArguments(arity) + ")).");
}

void PrologWrapper::compileFile(const string& filePath) {
    PlCall("qcompile(\"" + filePath + "\").");
}

bool PrologWrapper::loadFileIfExist(const string& filePath) {
    if (debugUI) {
        return true;
    }

    try {
        FILE* file = fopen(filePath.data(), "r");
        if (file != NULL) {
            fclose(file);
            spdlog::get(ErrorManager::TimerTag)->info("load file: {}", filePath);
            debug_prolog_file << (":-ensure_loaded(\"" + filePath + "\").") << "\n";
            PlCall("ensure_loaded(\"" + filePath + "\").");
            return true;
        } else {
            spdlog::get(ErrorManager::TimerTag)->warn("did not load file: {}", filePath);
            return false;
        }
    } catch (PlException& e) {
        easyPrint(e.as_string());
        return false;
    }
}

void PrologWrapper::unLoadFile(const string& filePath) {
    PlCall("unload_file(\"" + filePath + "\").");
}

void PrologWrapper::plCall(const string& clause) {
    debug_prolog_file << (":-" + clause + ".") << "\n";
    debug_prolog_file.flush();
    PlCall(clause + ".");
}


void PrologWrapper::loadTypeKeyAddressable(const string& typeKey) {
    debug_prolog_file << (":-load_addressable(\"" + typeKey + "\").") << "\n";
    debug_prolog_file.flush();
    PlCall("load_addressable(\"" + typeKey + "\").");
}

void PrologWrapper::loadTypeKeyUnaddressable(const string& typeKey) {
    debug_prolog_file << (":-load_unaddressable(\"" + typeKey + "\").") << "\n";
    debug_prolog_file.flush();
    PlCall("load_unaddressable(\"" + typeKey + "\").");
}
