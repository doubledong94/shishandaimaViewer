#include "../../util/util.h"
#include "../syntaxObject/Modifier.h"
#include "../javaParser/JavaParser.h"
#include "../syntaxObject/JavaHeaderFile.h"
#include "../syntaxObject/AntlrNodeToSyntaxObjectConverter.h"
#include "../javaParser/JavaParserBaseVisitor.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "ParseTreeToHeaderObjVisitor.h"


void ParseTreeToHeaderObjVisitor::setSrcFilePath(const string& filePath) {
    AddressableInfo::addcompilationUnitLock.lock();
    AddressableInfo::filePath2compilationUnits[filePath] = header;
    AddressableInfo::addcompilationUnitLock.unlock();
}

list<FieldOrParameter*> ParseTreeToHeaderObjVisitor::convertVariableObj(VariableDeclaration* variableDeclaration) {
    list<FieldOrParameter*> fields;
    for (auto& nameAndValueCount : variableDeclaration->nameAndValueCount) {
        FieldOrParameter* fieldOrParameter = new FieldOrParameter();
        fieldOrParameter->flag = variableDeclaration->flag;
        fieldOrParameter->name = nameAndValueCount.name.back();
        fieldOrParameter->typeName = new TypeName();
        fieldOrParameter->typeName->copy(&(variableDeclaration->typeType));
        fieldOrParameter->typeName->dim += nameAndValueCount.dim;
        fields.push_back(fieldOrParameter);
    }
    return fields;
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

any ParseTreeToHeaderObjVisitor::visitCompilationUnit(JavaParser::CompilationUnitContext* ctx) {
    if (ctx->packageDeclaration() != nullptr) {
        header->package = ctx->packageDeclaration()->qualifiedName()->getText();
    }
    for (auto& imports : ctx->importDeclaration()) {
        imports->accept(this);
    }
    typeStack.push_back(&(header->types));
    for (auto& typeDeclaration : ctx->typeDeclaration()) {
        typeDeclaration->accept(this);
    }
    typeStack.pop_back();
    return 0;
}
any ParseTreeToHeaderObjVisitor::visitImportDeclaration(JavaParser::ImportDeclarationContext* ctx) {
    bool importAll = ctx->importAll != nullptr;
    bool staticImport = ctx->STATIC() != nullptr;
    string importedStr = ctx->qualifiedName()->getText();
    if (not staticImport) {
        if (not importAll) {
            header->importedTypes.push_back(importedStr);
        } else {
            header->importedPackageOrType.push_back(importedStr);
        }
    } else {
        if (not importAll) {
            header->staticImported.push_back(importedStr);
        } else {
            header->starStaticImported.push_back(importedStr);
        }
    }
    return 0;
}

any ParseTreeToHeaderObjVisitor::visitTypeDeclaration(JavaParser::TypeDeclarationContext* ctx) {
    if (ctx->annotationTypeDeclaration()) {
        return 0;
    }
    auto type = new Type();
    AntlrNodeToSyntaxObjectConverter::convertTypeDeclaration(ctx, type);
    typeStack.back()->push_back(type);
    pushStackForType(type);

    if (ctx->classDeclaration() != nullptr) {
        visitClassDeclaration(ctx->classDeclaration());
    } else if (ctx->interfaceDeclaration() != nullptr) {
        visitInterfaceDeclaration(ctx->interfaceDeclaration());
    } else if (ctx->enumDeclaration() != nullptr) {
        visitEnumDeclaration(ctx->enumDeclaration());
    }

    popStack();
    return 0;
}
any ParseTreeToHeaderObjVisitor::visitClassDeclaration(JavaParser::ClassDeclarationContext* ctx) {
    for (auto& classBodyDec : ctx->classBody()->classBodyDeclaration()) {
        visitClassBodyDeclaration(classBodyDec);
    }
    return 0;
}
any ParseTreeToHeaderObjVisitor::visitClassBodyDeclaration(JavaParser::ClassBodyDeclarationContext* ctx) {
    if (ctx->memberDeclaration() != nullptr) {
        if (ctx->memberDeclaration()->fieldDeclaration() != nullptr) {
            VariableDeclaration variableDeclaration;
            AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationField(ctx, &variableDeclaration);
            auto fields = convertVariableObj(&variableDeclaration);
            FOR_EACH_ITEM(fields, fieldStack.back()->push_back(item););
        } else if (ctx->memberDeclaration()->methodDeclaration() != nullptr or ctx->memberDeclaration()->constructorDeclaration() != nullptr) {
            auto method = new Method();
            AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationMethod(ctx, method);
            if (ctx->memberDeclaration()->methodDeclaration()) {
                methodStack.back()->push_back(method);
            } else {
                constructorStack.back()->push_back(method);
            }
        } else if (ctx->memberDeclaration()->classDeclaration() != nullptr or
            ctx->memberDeclaration()->interfaceDeclaration() != nullptr
            or ctx->memberDeclaration()->enumDeclaration()) {
            auto type = new Type();
            AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationType(ctx, type);
            typeStack.back()->push_back(type);
            pushStackForType(type);
            if (ctx->memberDeclaration()->classDeclaration() != nullptr) {
                visitClassDeclaration(ctx->memberDeclaration()->classDeclaration());
            } else if (ctx->memberDeclaration()->interfaceDeclaration() != nullptr) {
                visitInterfaceDeclaration(ctx->memberDeclaration()->interfaceDeclaration());
            } else if (ctx->memberDeclaration()->enumDeclaration() != nullptr) {
                visitEnumDeclaration(ctx->memberDeclaration()->enumDeclaration());
            }
            popStack();
        }
    }
    return 0;
}
any ParseTreeToHeaderObjVisitor::visitInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx) {
    for (auto& interfaceBodyDec : ctx->interfaceBody()->interfaceBodyDeclaration()) {
        if (interfaceBodyDec->interfaceMemberDeclaration() != nullptr) {
            visitInterfaceBodyDeclaration(interfaceBodyDec);
        }
    }
    return 0;
}
any ParseTreeToHeaderObjVisitor::visitInterfaceBodyDeclaration(JavaParser::InterfaceBodyDeclarationContext* ctx) {
    if (ctx->interfaceMemberDeclaration() != nullptr) {
        if (ctx->interfaceMemberDeclaration()->constDeclaration() != nullptr) {
            VariableDeclaration variableDeclaration;
            AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationConst(ctx, &variableDeclaration);
            auto fields = convertVariableObj(&variableDeclaration);
            FOR_EACH_ITEM(fields, fieldStack.back()->push_back(item););
        } else if (ctx->interfaceMemberDeclaration()->interfaceMethodDeclaration() != nullptr) {
            auto method = new Method();
            AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationMethod(ctx, method);
            methodStack.back()->push_back(method);
        } else if (ctx->interfaceMemberDeclaration()->classDeclaration() != nullptr or
            ctx->interfaceMemberDeclaration()->interfaceDeclaration() != nullptr or
            ctx->interfaceMemberDeclaration()->enumDeclaration() != nullptr) {
            auto type = new Type();
            AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationType(ctx, type);
            typeStack.back()->push_back(type);
            pushStackForType(type);
            if (ctx->interfaceMemberDeclaration()->classDeclaration() != nullptr) {
                ctx->interfaceMemberDeclaration()->classDeclaration()->accept(this);
            } else if (ctx->interfaceMemberDeclaration()->interfaceDeclaration() != nullptr) {
                ctx->interfaceMemberDeclaration()->interfaceDeclaration()->accept(this);
            } else if (ctx->interfaceMemberDeclaration()->enumDeclaration() != nullptr) {
                ctx->interfaceMemberDeclaration()->enumDeclaration()->accept(this);
            }
            popStack();
        }
    }
    return 0;
}

any ParseTreeToHeaderObjVisitor::visitEnumDeclaration(JavaParser::EnumDeclarationContext* ctx) {
    if (ctx->enumConstants()) {
        for (auto& enumConst : ctx->enumConstants()->enumConstant()) {
            enumStack.back()->push_back(enumConst->identifier()->getText());
        }
    }
    if (ctx->enumBodyDeclarations()) {
        for (auto& classBodyDec : ctx->enumBodyDeclarations()->classBodyDeclaration()) {
            if (classBodyDec->memberDeclaration()) {
                visitClassBodyDeclaration(classBodyDec);
            }
        }
    }
    return 0;
}

