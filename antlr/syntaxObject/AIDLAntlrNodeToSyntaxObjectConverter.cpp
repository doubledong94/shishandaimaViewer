#include "../../util/util.h"
#include "../aidlParser/AIDLParser.h"
#include "Modifier.h"
#include "JavaHeaderFile.h"
#include "AIDLAntlrNodeToSyntaxObjectConverter.h"

void AIDLAntlrNodeToSyntaxObjectConverter::convertInterfaceDeclaration(AIDLParser::Interface_declContext* ctx, Type* type) {
    type->flag |= Modifier::INTERFACE;
    type->name = ctx->qualified_name()->getText();
}

void AIDLAntlrNodeToSyntaxObjectConverter::convertMethodDeclaration(AIDLParser::Method_declContext* ctx, Method* method) {
    method->name = ctx->identifier()->getText();
    method->returnTypeName = new TypeName();
    convertTypeName(ctx->type(), method->returnTypeName);
    if (ctx->arg_non_empty_list()) {
        convertParameters(ctx->arg_non_empty_list(), method->parameters);
    }
}

void AIDLAntlrNodeToSyntaxObjectConverter::convertTypeName(AIDLParser::TypeContext* ctx, TypeName* typeName) {
    if (ctx->VOID()) {
        typeName->typeName.push_back("void");
    } else {
        for (auto& idContext : ctx->non_array_type()->qualified_name()->identifier()) {
            typeName->typeName.push_back(idContext->getText());
        }
        typeName->dim = ctx->LBRACK().size();
    }
}

void AIDLAntlrNodeToSyntaxObjectConverter::convertParameters(AIDLParser::Arg_non_empty_listContext* ctx, list<FieldOrParameter*>& parameters) {
    for (auto& arg : ctx->arg()) {
        FieldOrParameter* fieldOrParameter = new FieldOrParameter();
        fieldOrParameter->name = arg->identifier()->getText();
        fieldOrParameter->typeName = new TypeName();
        convertTypeName(arg->type(), fieldOrParameter->typeName);
        parameters.push_back(fieldOrParameter);
    }
}
