#include "../../util/util.h"
#include "../syntaxObject/Modifier.h"
#include "../javaParser/JavaParser.h"
#include "../syntaxObject/JavaHeaderFile.h"
#include "../javaParser/JavaParserBaseVisitor.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "ParseTreeToHeaderObjVisitor.h"


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

