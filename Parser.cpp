#include "util/util.h"
#include "util/ThreadPool.h"
#include "antlr4-runtime.h"
#include "antlr/javaParser/JavaParser.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "antlr/syntaxObject/AntlrNodeToSyntaxObjectConverter.h"
#include "file/FileManager.h"
#include "antlr/javaParser/JavaLexer.h"
#include "antlr/javaParser/JavaParserBaseVisitor.h"
#include "addressableInfo/AddressableInfo.h"
#include "antlr/visitor/HeaderEnterVisitor.h"
#include "antlr/visitor/ParseTreeToHeaderObjVisitor.h"
#include "runtime/codestructure/CodeStructure.h"
#include "runtime/codestructure/Relation.h"
#include "runtime/codestructure/Sentence.h"
#include "runtime/codestructure/CodeBlock.h"
#include "runtime/codestructure/SplitCodeBlocks.h"
#include "runtime/ScopeAndEnv.h"
#include "antlr/visitor/RuntimeVisitor.h"
#include "addressableInfo/GlobalInfo.h"
#include "SWI-cpp.h"
#include "prolog/PrologConstructor.h"
#include "prolog/PrologWrapper.h"
#include "error/ErrorManager.h"
#include "prolog/PrologDataBaseGen.h"
#include "absl/time/clock.h"
#include "Parser.h"

static bool debug_parser = false;

void ErrorListener::syntaxError(antlr4::Recognizer* recognizer, antlr4::Token* offendingSymbol, size_t line, size_t charPositionInLine, const string& msg, std::exception_ptr e) {
    easyPrint("xxxxxxxxxxxxxxxxxxxxxxxxxx error start xxxxxxxxxxxxxxxxxxxxxxxxxx");
    easyPrint("xxxxxx file:", filePath1);
    easyPrint("xxxxxx file:", filePath2);
    easyPrint("xxxxxx line:", to_string(line));
    easyPrint("xxxxxx pos:", to_string(charPositionInLine));
    easyPrint("xxxxxx msg:", msg);
    easyPrint("xxxxxxxxxxxxxxxxxxxxxxxxxxx error end xxxxxxxxxxxxxxxxxxxxxxxxxx");
}

ErrorListener::ErrorListener(const char* filePath1, const char* filePath2) {
    this->filePath1 = filePath1;
    this->filePath2 = filePath2;
}

void app::Parser::visit(const char* originSrcFilePath, JavaParser* parser, ParseTreeToHeaderObjVisitor* visitor) {
    parser->compilationUnit()->accept(visitor);
    visitor->setSrcFilePath(originSrcFilePath);
    counterLock.lock();
    currentCountPass1++;
    counterLock.unlock();
}

void app::Parser::visit(const char* originSrcFilePath, JavaParser* parser, ClassLevelVisitor* visitor) {
    // progress bar
    counterLock.lock();
    currentCountPass2++;
    spdlog::get(ErrorManager::DebugTag)->info("{}: {}", currentCountPass2, originSrcFilePath);
    // if (currentCountPass2 < 2800) {
    //     counterLock.unlock();
    //     return;
    // }
    counterLock.unlock();
    // do runtime
    parser->compilationUnit()->accept(visitor);

    map<Term*, int> unaddressableMultiFileFunctorName2ArgCount;
    unaddressableMultiFileFunctorName2ArgCount[HEAD_RUNTIME_KEY] = 4;
    unaddressableMultiFileFunctorName2ArgCount[HEAD_DATA_FLOW] = 3;
    unaddressableMultiFileFunctorName2ArgCount[HEAD_CODE_ORDER] = 3;
    unaddressableMultiFileFunctorName2ArgCount[HEAD_RUNTIME_READ] = 3;
    unaddressableMultiFileFunctorName2ArgCount[HEAD_RUNTIME_WRITE] = 3;

    //runGraphAndSave
    list<string> prologLines;
    FOR_EACH_ITEM(unaddressableMultiFileFunctorName2ArgCount, prologLines.push_back(getMultiFileDirective(item.first->toString(), to_string(item.second))););
    PrologDataBaseGen::genPrologDataBase(prologLines);
    PrologConstructor::writeToPrologFile(FileManager::prologUnaddressableFileDir + FileManager::convertFilePath2PrologFile(originSrcFilePath), prologLines);
    CodeBlock::releaseMethodCodeBlocks();
    ErrorManager::mk2errorInfo.clear();
}

void app::Parser::parse(const string& path) {
    parsing = true;
    PrologDataBaseGen::init();
    int64_t start = absl::GetCurrentTimeNanos();
    PL_thread_attach_engine(NULL);
    FileManager::getFiles(path, ".java");

    spdlog::get(ErrorManager::DebugTag)->info("all file count: {}", FileManager::allFiles.size());
    spdlog::get(ErrorManager::DebugTag)->info("updated file count: {}", FileManager::updatedFiles.size());

    PrologConstructor::beforeParseAll();
    AddressableInfo::beforeParseAll();
    GlobalInfo::beforeParseAll();

    spdlog::get(ErrorManager::DebugTag)->info("updated file count: {}", FileManager::updatedFiles.size());

    totalCountPass = FileManager::allFiles.size();
    currentCountPass1 = 0;
    currentCountPass2 = 0;
    ThreadPool threadPool(debug_parser ? 1 : 4);

    for (auto& filePath : FileManager::updatedFiles) {
        threadPool.submit([&]() {
            parseFile<JavaLexer, JavaParser, ParseTreeToHeaderObjVisitor>(filePath.data(), filePath.data());
            parseTime = (absl::GetCurrentTimeNanos() - start) / 1000000000;
            });
    }
    threadPool.wait();

    AddressableInfo::serializeHeader();

    Header::EnterClassPhase enterClassPhase;
    enterClassPhase.run();
    for (auto& filePath : enterClassPhase.duplicateTypeFile) {
        FileManager::updatedFiles.erase(filePath);
        FileManager::allFiles.erase(filePath);
    }

    AddressableInfo::afterFirstRound();
    PackageScopeAndEnv::addScopeAndEnvForAllPackage();
    FileScopeAndEnv::addImportedTypeNameScopeAndEnvForAllFile();
    ClassScopeAndEnv::addClassScopeAndEnvForAllTypes();
    Header::HierarchyPhase::resolveHierarchy();

    Header::MemeberPhase memberPhase;
    memberPhase.run();
    ClassScopeAndEnv::addFieldAndMethodNamesForAllTypes();
    FileScopeAndEnv::addImportedFieldAndMethodNameScopeAndEnvForAllFile();

    // runtime round
    for (auto& filePath : debug_parser ? FileManager::allFiles : FileManager::updatedFiles) {
        threadPool.submit([&]() {
            parseFile<JavaLexer, JavaParser, ClassLevelVisitor>(filePath.data(), filePath.data());
            parseTime = (absl::GetCurrentTimeNanos() - start) / 1000000000;
            });
    }
    threadPool.wait();
    GlobalInfo::saveGlobalInfo();
    AddressableInfo::saveAddressableInfo();
    PL_thread_destroy_engine();
    release();
    parseTime = (absl::GetCurrentTimeNanos() - start) / 1000000000;
    parsing = false;
}

void app::Parser::release() {
    for (auto& typeInfo : AddressableInfo::typeKey2typeInfo) {
        if (typeInfo.second != nullptr) {
            ClassScopeAndEnv::release(typeInfo.second->classScopeAndEnv);
        }
    }
    FileScopeAndEnv::release();
    PackageScopeAndEnv::release();
    AddressableInfo::release();
    GlobalInfo::release();
}

float app::Parser::getProgressPass1() {
    if (parsing) {
        return currentCountPass1 / (float)totalCountPass;
    } else {
        return 0;
    }
}

string app::Parser::getProgressTextPass1() {
    if (parsing) {
        return to_string(currentCountPass1) + "/" + to_string(totalCountPass);
    } else {
        return "done";
    }
}

float app::Parser::getProgressPass2() {
    if (parsing) {
        return currentCountPass2 / (float)totalCountPass;
    } else {
        return 0;
    }
}

string app::Parser::getProgressTextPass2() {
    if (parsing) {
        return to_string(currentCountPass2) + "/" + to_string(totalCountPass);
    } else {
        return "done";
    }
}

string app::Parser::getParseTime() {
    int minute = parseTime / 60;
    int seconds = parseTime % 60;
    return "parse time: " + to_string(minute) + "m " + to_string(seconds) + "s";
}

