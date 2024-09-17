#include "util/util.h"
#include "antlr/syntaxObject/Modifier.h"
#include "antlr/javaParser/JavaParser.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"
#include "antlr/javaParser/JavaParserBaseVisitor.h"
#include "addressableInfo/AddressableInfo.h"
#include "antlr/visitor/ParseTreeToHeaderObjVisitor.h"


void ParseTreeToHeaderObjVisitor::setSrcFilePath(const string& filePath) {
    AddressableInfo::addcompilationUnitLock.lock();
    AddressableInfo::filePath2compilationUnits[filePath] = header;
    AddressableInfo::addcompilationUnitLock.unlock();
}

void ParseTreeToHeaderObjVisitor::pushStackForType(Type* type) {
    typeStack.push_back(&(type->innerTypes));
    enumStack.push_back(&(type->enumConstants));
    fieldStack.push_back(&(type->fields));
    constructorStack.push_back(&(type->constructors));
    methodStack.push_back(&(type->methods));
}

void ParseTreeToHeaderObjVisitor::popStack() {
    typeStack.pop_back();
    enumStack.pop_back();
    fieldStack.pop_back();
    constructorStack.pop_back();
    methodStack.pop_back();
}

