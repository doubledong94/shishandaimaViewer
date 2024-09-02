#include "../../util/util.h"
#include "../syntaxObject/Modifier.h"
#include "../syntaxObject/JavaHeaderFile.h"
#include "../aidlParser/AIDLParser.h"
#include "../syntaxObject/AIDLAntlrNodeToSyntaxObjectConverter.h"
#include "../../addressableInfo/AddressableInfo.h"
#include "ParseTreeToHeaderObjVisitor.h"
#include "../aidlParser/AIDLParserBaseVisitor.h"
#include "AIDLParseTreeToHeaderObjVisitor.h"

std::any AIDLParseTreeToHeaderObjVisitor::visitCompilationUnit(AIDLParser::CompilationUnitContext* ctx) {
    if (ctx->optional_package()) {
        header->package = ctx->optional_package()->qualified_name()->getText();
    }
    if (ctx->imports()) {
        for (auto& importI : ctx->imports()->importI()) {
            importI->accept(this);
        }
    }
    header->importedTypes.push_back("android.os.IBinder");
    header->importedTypes.push_back("android.os.IInterface");
    header->importedTypes.push_back("android.os.Binder");
    typeStack.push_back(&(header->types));
    for (auto& decl : ctx->decls()->decl()) {
        if (decl->unannotated_decl()->interface_decl()) {
            decl->unannotated_decl()->interface_decl()->accept(this);
        }
    }
    typeStack.pop_back();
    return std::any();
}

std::any AIDLParseTreeToHeaderObjVisitor::visitImportI(AIDLParser::ImportIContext* ctx) {
    header->importedTypes.push_back(ctx->qualified_name()->getText());
    return 0;
}

std::any AIDLParseTreeToHeaderObjVisitor::visitInterface_decl(AIDLParser::Interface_declContext* ctx) {
    auto type = new Type();
    AIDLAntlrNodeToSyntaxObjectConverter::convertInterfaceDeclaration(ctx, type);
    TypeName* typeName = new TypeName();
    typeName->typeName.push_back("IInterface");
    type->extendsTypeNames.push_back(typeName);
    typeStack.back()->push_back(type);
    pushStackForType(type);
    if (ctx->interface_members()) {
        for (auto& methodMember : ctx->interface_members()->method_decl()) {
            methodMember->accept(this);
        }
        for (auto& decl : ctx->interface_members()->decl()) {
            if (decl->unannotated_decl()->interface_decl()) {
                decl->unannotated_decl()->interface_decl()->accept(this);
            }
        }
    }
    addGeneratedClass(type);
    popStack();
    return 0;
}

std::any AIDLParseTreeToHeaderObjVisitor::visitMethod_decl(AIDLParser::Method_declContext* ctx) {
    auto method = new Method();
    AIDLAntlrNodeToSyntaxObjectConverter::convertMethodDeclaration(ctx, method);
    methodStack.back()->push_back(method);
    return 0;
}

void AIDLParseTreeToHeaderObjVisitor::addGeneratedClass(Type* type) {
    TypeName* interfaceName = new TypeName();
    interfaceName->typeName.push_back(type->name);
    TypeName* IBinderType = new TypeName();
    IBinderType->typeName.push_back("IBinder");
    TypeName* binderType = new TypeName();
    binderType->typeName.push_back("Binder");

    // asBinder method
    Method* asBinder = new Method();
    asBinder->name = "asBinder";
    asBinder->returnTypeName = IBinderType;
    // asInterface method
    Method* asInterface = new Method();
    asInterface->name = "asInterface";
    asInterface->returnTypeName = interfaceName;

    // Default class
    Type* defaultType = new Type();
    type->innerTypes.push_back(defaultType);
    defaultType->name = "Default";
    defaultType->flag |= Modifier::CLASS;
    defaultType->implementsTypeNames.push_back(interfaceName);
    defaultType->methods = type->methods;
    defaultType->methods.push_back(asBinder);
    // stub class
    Type* stubType = new Type();
    type->innerTypes.push_back(stubType);
    stubType->name = "Stub";
    stubType->flag |= Modifier::CLASS;
    stubType->extendsTypeNames.push_back(binderType);
    stubType->implementsTypeNames.push_back(interfaceName);
    stubType->methods = type->methods;
    stubType->methods.push_back(asBinder);
    stubType->methods.push_back(asInterface);
    // proxy class
    Type* proxyType = new Type();
    stubType->innerTypes.push_back(proxyType);
    proxyType->name = "Proxy";
    proxyType->flag |= Modifier::CLASS;
    proxyType->implementsTypeNames.push_back(interfaceName);
    proxyType->methods = type->methods;
    proxyType->methods.push_back(asBinder);


}
