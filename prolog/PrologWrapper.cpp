#include "../util/util.h"
#include "../antlr/syntaxObject/JavaHeaderFile.h"
#include "../addressableInfo/AddressableInfo.h"
#include "../file/FileManager.h"
#include "SWI-cpp2.h"
#include "../GraphAttributes.h"
#include "PrologConstructor.h"
#include "PrologWrapper.h"
#include "../error/ErrorManager.h"

PlEngine* PrologWrapper::e = NULL;

ofstream debug_prolog_file;

bool PrologWrapper::init() {
    e = new PlEngine("");
    bool loaded = true;
    loaded &= loadFileIfExist(FileManager::prologGlobalInfo_package2typeKey);
    loaded &= loadFileIfExist(FileManager::prologGlobalInfo_typeKey2itUseTypeKeys);
    loaded &= loadFileIfExist(FileManager::prologGlobalInfo_typeKey2AddressableFilePath);
    loaded &= loadFileIfExist(FileManager::prologGlobalInfo_typeKey2UnaddressableFilePath);
    loaded &= loadFileIfExist(FileManager::prologGlobalInfo_baseRuleFile);
    debug_prolog_file.open("debug_prolog_file.txt");
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

void PrologWrapper::queryList(CompoundTerm* term, vector<Term*>& retList) {
    retList.clear();
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
            for (int i : outputIndex) {
                PlTerm plT = av[i];
                retList.push_back(convertPlTermToTerm(&plT));
            }
        }
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
}

void PrologWrapper::queryLoadedTypeKeys(list<string>& loadedTypeKeys) {
    loadedTypeKeys.clear();
    vector<Term*> ret;
    auto* plTerm = PooledItem<CompoundTerm>::getInstance();
    plTerm->head = HEAD_LOADED;
    plTerm->addVarTermArg();
    queryList(plTerm, ret);
    FOR_EACH_ITEM(ret, loadedTypeKeys.push_back(REMOVE_QUOTATION(item->toString())););
}

void PrologWrapper::declareFun(const string& functorName, int arity) {
    PlCall("dynamic " + functorName + "/" + to_string(arity) + ".");
}

void PrologWrapper::addFact(const string& factStr) {
    debug_prolog_file << factStr << "." << "\n";
    debug_prolog_file.flush();
    PlCall("assertz(" + factStr + ").");
}

bool PrologWrapper::factExist(CompoundTerm* factTerm) {
    vector<Term*> ret;
    queryList(factTerm, ret);
    return !ret.empty();
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
        debug_prolog_file << ("retractall(" + functorName + "(" + makeUnderScoreArguments(arity) + ")).") << "\n";
        debug_prolog_file.flush();
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


void PrologWrapper::loadTypeKeyAddressable(const string& typeKey) {
    debug_prolog_file << ("load_addressable(\"" + typeKey + "\").") << "\n";
    debug_prolog_file.flush();
    PlCall("load_addressable(\"" + typeKey + "\").");
}

void PrologWrapper::loadTypeKeyUnaddressable(const string& typeKey) {
    debug_prolog_file << ("load_unaddressable(\"" + typeKey + "\").") << "\n";
    debug_prolog_file.flush();
    PlCall("load_unaddressable(\"" + typeKey + "\").");
}
