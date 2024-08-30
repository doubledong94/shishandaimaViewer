#include "../../util/util.h"
#include "../javaParser/JavaParser.h"
#include "Modifier.h"
#include "JavaHeaderFile.h"
#include "AntlrNodeToSyntaxObjectConverter.h"

void AntlrNodeToSyntaxObjectConverter::convertTypeTypeOrVoid(JavaParser::TypeTypeOrVoidContext* ctx, TypeName* typeName) {
    if (ctx->VOID()) {
        typeName->typeName.emplace_back(ctx->VOID()->getText());
    } else {
        convertTypeType(ctx->typeType(), typeName);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertTypeType(JavaParser::TypeTypeContext* ctx, TypeName* typeName, vector<JavaParser::VariableModifierContext*> variableModivierCtxs) {
    if (ctx->primitiveType()) {
        typeName->typeName.emplace_back(ctx->primitiveType()->getText());
    } else {
        for (auto*& variableModivierCtx : variableModivierCtxs) {
            if (variableModivierCtx->annotation() and variableModivierCtx->annotation()->altAnnotationQualifiedName()) {
                vector<JavaParser::IdentifierContext*> ids = variableModivierCtx->annotation()->altAnnotationQualifiedName()->identifier();
                for (int i = 0;i < ids.size() - 1;i++) {
                    typeName->typeName.push_back(ids[i]->getText());
                }
            }
        }
        convertClassOrInterfaceType(ctx->classOrInterfaceType(), typeName);
        if (ctx->classOrInterfaceType()->typeArguments().size()) {
            convertTypeArguments(ctx->classOrInterfaceType()->typeArguments().back(), typeName->typeArgs);
        }
    }
    typeName->dim = ctx->LBRACK().size();
}

void AntlrNodeToSyntaxObjectConverter::convertClassOrInterfaceType(JavaParser::ClassOrInterfaceTypeContext* ctx, TypeName* typeName) {
    for (auto identifier : ctx->identifier()) {
        typeName->typeName.emplace_back(identifier->getText());
    }
}

void AntlrNodeToSyntaxObjectConverter::convertExplicitGenericInvocationSuffix(JavaParser::ExplicitGenericInvocationSuffixContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->SUPER() != nullptr) {
        methodCall->name.emplace_back(ctx->SUPER()->getText());
        convertSuperSuffix(ctx->superSuffix(), methodCall);
    } else {
        methodCall->name.emplace_back(ctx->identifier()->getText());
        convertArguments(ctx->arguments(), methodCall);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertSuperSuffix(JavaParser::SuperSuffixContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->identifier() != nullptr) {
        methodCall->name.emplace_back(ctx->identifier()->getText());
        if (ctx->arguments() != nullptr) {
            convertArguments(ctx->arguments(), methodCall);
        }
    } else {
        convertArguments(ctx->arguments(), methodCall);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertArguments(JavaParser::ArgumentsContext* ctx, NameAndRelatedExp* methodCall) {
    methodCall->arguments = ctx->expressionList();
}

void AntlrNodeToSyntaxObjectConverter::convertMethodCall(JavaParser::MethodCallContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->identifier() != nullptr) {
        methodCall->name.emplace_back(ctx->identifier()->getText());
    }
    methodCall->arguments = ctx->expressionList();
}

void AntlrNodeToSyntaxObjectConverter::convertInnerCreator(JavaParser::InnerCreatorContext* ctx, NameAndRelatedExp* methodCall) {
    methodCall->name.push_back(ctx->identifier()->getText());
    convertArguments(ctx->classCreatorRest()->arguments(), methodCall);
}

void AntlrNodeToSyntaxObjectConverter::convertCreator(JavaParser::CreatorContext* ctx, NameAndRelatedExp* methodCall) {
    convertCreatedName(ctx->createdName(), methodCall);
    if (ctx->arrayCreatorRest() != nullptr) {
        if (ctx->arrayCreatorRest()->arrayInitializer() != nullptr) {
            convertArrayInitializerNoRecur(ctx->arrayCreatorRest()->arrayInitializer(), methodCall);
        } else {
            methodCall->dimExps = ctx->arrayCreatorRest()->expression();
            methodCall->dim = ctx->arrayCreatorRest()->LBRACK().size();
        }
    } else if (ctx->classCreatorRest() != nullptr) {
        convertArguments(ctx->classCreatorRest()->arguments(), methodCall);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertCreatedName(JavaParser::CreatedNameContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->primitiveType() != nullptr) {
        methodCall->name.push_back(ctx->primitiveType()->getText());
    } else {
        for (auto identifier : ctx->identifier()) {
            methodCall->name.push_back(identifier->getText());
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertArrayInitializerNoRecur(JavaParser::ArrayInitializerContext* ctx, NameAndRelatedExp* methodCall) {
    methodCall->dim = 1;
    convertArrayInitializerRecurForDim(ctx, methodCall);
    methodCall->arrayInitValues = ctx;
}


void AntlrNodeToSyntaxObjectConverter::convertArrayInitializerRecurForDim(JavaParser::ArrayInitializerContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->variableInitializer().empty()) {
        return;
    }
    if (ctx->variableInitializer(0)->arrayInitializer() != nullptr) {
        methodCall->dim++;
        convertArrayInitializerRecurForDim(ctx->variableInitializer(0)->arrayInitializer(), methodCall);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertVariableInitializerNoRecur(JavaParser::VariableInitializerContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->arrayInitializer() != nullptr) {
        convertArrayInitializerNoRecur(ctx->arrayInitializer(), methodCall);
    } else if (ctx->expression() != nullptr) {
        methodCall->initExpression = ctx->expression();
    }
}

void AntlrNodeToSyntaxObjectConverter::convertVariableDeclarators(JavaParser::VariableDeclaratorsContext* ctx, VariableDeclaration* variableDeclarator) {
    for (auto& variableDeclaratorI : ctx->variableDeclarator()) {
        NameAndRelatedExp nameAndRelatedExpCount;
        if (variableDeclaratorI->variableInitializer() != nullptr) {
            convertVariableInitializerNoRecur(variableDeclaratorI->variableInitializer(), &nameAndRelatedExpCount);
        }
        nameAndRelatedExpCount.name.emplace_back(variableDeclaratorI->variableDeclaratorId()->identifier()->getText());
        nameAndRelatedExpCount.dim = variableDeclaratorI->variableDeclaratorId()->LBRACK().size();
        variableDeclarator->nameAndValueCount.push_front(nameAndRelatedExpCount);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertLocalVariableDeclaration(JavaParser::LocalVariableDeclarationContext* ctx, VariableDeclaration* variableDeclarator) {
    if (ctx->typeType() != nullptr) {
        convertTypeType(ctx->typeType(), &(variableDeclarator->typeType), ctx->variableModifier());
        convertVariableDeclarators(ctx->variableDeclarators(), variableDeclarator);
        FOR_EACH_ITEM(variableDeclarator->nameAndValueCount, item.dim += variableDeclarator->typeType.dim;);
    } else {
        variableDeclarator->typeType.typeName.push_back(ctx->VAR()->getText());
        NameAndRelatedExp name;
        name.name.push_back(ctx->identifier()->getText());
        name.initExpression = ctx->expression();
        variableDeclarator->nameAndValueCount.push_back(name);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertLocalVariableFromResource(JavaParser::ResourceContext* ctx, VariableDeclaration* variableDeclarator) {
    NameAndRelatedExp name;
    if (ctx->classOrInterfaceType()) {
        convertClassOrInterfaceType(ctx->classOrInterfaceType(), &(variableDeclarator->typeType));
        name.name.push_back(ctx->variableDeclaratorId()->identifier()->getText());
    } else {
        variableDeclarator->typeType.typeName.push_back(ctx->VAR()->getText());
        name.name.push_back(ctx->identifier()->getText());
    }
    name.initExpression = ctx->expression();
    variableDeclarator->nameAndValueCount.push_back(name);
}

void AntlrNodeToSyntaxObjectConverter::convertFieldDeclaration(JavaParser::FieldDeclarationContext* ctx, VariableDeclaration* variableDeclarator) {
    convertTypeType(ctx->typeType(), &(variableDeclarator->typeType));
    convertVariableDeclarators(ctx->variableDeclarators(), variableDeclarator);
    FOR_EACH_ITEM(variableDeclarator->nameAndValueCount, item.dim += variableDeclarator->typeType.dim;);
}

void AntlrNodeToSyntaxObjectConverter::convertClassOrInterfaceModifier(JavaParser::ClassOrInterfaceModifierContext* ctx, unsigned int* flag) {
    if (ctx->STATIC()) {
        *flag |= Modifier::STATIC;
    }
    if (ctx->FINAL()) {
        *flag |= Modifier::FINAL;
    }
    if (ctx->PUBLIC()) {
        *flag |= Modifier::PUBLIC;
    }
    if (ctx->PRIVATE()) {
        *flag |= Modifier::PRIVATE;
    }
    if (ctx->PROTECTED()) {
        *flag |= Modifier::PROTECTED;
    }
    if (ctx->ABSTRACT()) {
        *flag |= Modifier::ABSTRACT;
    }
}

void AntlrNodeToSyntaxObjectConverter::convertClassOrInterfaceModifiers(const std::vector<JavaParser::ClassOrInterfaceModifierContext*>& ctx, unsigned int* flag) {
    for (auto& modifier : ctx) {
        convertClassOrInterfaceModifier(modifier, flag);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertModifier(JavaParser::ModifierContext* ctx, unsigned int* flag) {
    if (ctx->classOrInterfaceModifier() != nullptr) {
        convertClassOrInterfaceModifier(ctx->classOrInterfaceModifier(), flag);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertModifiers(const vector<JavaParser::ModifierContext*>& ctx, unsigned int* flag) {
    for (auto& modifier : ctx) {
        convertModifier(modifier, flag);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertTypeDeclaration(JavaParser::TypeDeclarationContext* ctx, Type* type) {
    convertClassOrInterfaceModifiers(ctx->classOrInterfaceModifier(), &type->flag);
    if (ctx->classDeclaration() != nullptr) {
        convertClassDeclaration(ctx->classDeclaration(), type);
    } else if (ctx->interfaceDeclaration() != nullptr) {
        convertInterfaceDeclaration(ctx->interfaceDeclaration(), type);
    } else if (ctx->enumDeclaration() != nullptr) {
        convertEnumDeclaration(ctx->enumDeclaration(), type);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertTypeParam(JavaParser::TypeParameterContext* ctx, TypeParam* typeParam) {
    typeParam->name = ctx->identifier()->getText();
    if (ctx->typeBound()) {
        for (auto& typeTypeContext : ctx->typeBound()->typeType()) {
            TypeName* boundI = new TypeName();
            convertTypeType(typeTypeContext, boundI);
            typeParam->bounds.push_back(boundI);
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertClassDeclaration(JavaParser::ClassDeclarationContext* ctx, Type* type) {
    type->flag |= Modifier::CLASS;
    type->name = ctx->identifier()->getText();
    if (ctx->super != nullptr) {
        TypeName* typeName = new TypeName();
        convertTypeType(ctx->super, typeName);
        type->extendsTypeNames.push_back(typeName);
    }
    if (ctx->interface != nullptr) {
        for (auto& typeType : ctx->interface->typeType()) {
            TypeName* typeName = new TypeName();
            convertTypeType(typeType, typeName);
            type->implementsTypeNames.push_back(typeName);
        }
    }
    convertTypeParameters(ctx->typeParameters(), type->typeParams);
}

void AntlrNodeToSyntaxObjectConverter::convertEnumDeclaration(JavaParser::EnumDeclarationContext* ctx, Type* type) {
    type->flag |= Modifier::ENUM;
    type->name = ctx->identifier()->getText();
    if (ctx->interface != nullptr) {
        for (auto& typeType : ctx->interface->typeType()) {
            TypeName* typeName = new TypeName();
            convertTypeType(typeType, typeName);
            type->implementsTypeNames.push_back(typeName);
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceDeclaration(JavaParser::InterfaceDeclarationContext* ctx, Type* type) {
    type->flag |= Modifier::INTERFACE;
    type->name = ctx->identifier()->getText();
    if (ctx->super != nullptr) {
        for (auto& typeType : ctx->super->typeType()) {
            TypeName* typeName = new TypeName();
            convertTypeType(typeType, typeName);
            type->extendsTypeNames.push_back(typeName);
        }
    }
    convertTypeParameters(ctx->typeParameters(), type->typeParams);
}

void AntlrNodeToSyntaxObjectConverter::convertMethodDeclaration(JavaParser::MethodDeclarationContext* ctx, Method* method) {
    method->name = ctx->identifier()->getText();
    method->returnTypeName = new TypeName();
    if (ctx->typeTypeOrVoid()->typeType() != nullptr) {
        convertTypeType(ctx->typeTypeOrVoid()->typeType(), method->returnTypeName);
    } else {
        method->returnTypeName->typeName.push_back(ctx->typeTypeOrVoid()->VOID()->getText());
    }
    method->isVariableParameter = convertFormalParameters(ctx->formalParameters(), method->parameters);
    convertTypeParameters(ctx->typeParameters(), method->typeParams);
}

void AntlrNodeToSyntaxObjectConverter::convertConstructorDeclaration(JavaParser::ConstructorDeclarationContext* ctx, Method* method) {
    method->name = ctx->identifier()->getText();
    method->returnTypeName = new TypeName();
    method->returnTypeName->typeName.push_back(method->name);
    method->isVariableParameter = convertFormalParameters(ctx->formalParameters(), method->parameters);
    convertTypeParameters(ctx->typeParameters(), method->typeParams);
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceMethodDeclaration(JavaParser::InterfaceMethodDeclarationContext* ctx, Method* method) {
    if (ctx->interfaceCommonBodyDeclaration()->identifier() == nullptr) {
        // parsing error
        return;
    }
    convertInterfaceMethodModifier(ctx, method);
    method->name = ctx->interfaceCommonBodyDeclaration()->identifier()->getText();
    method->returnTypeName = new TypeName();
    if (ctx->interfaceCommonBodyDeclaration()->typeTypeOrVoid()->typeType() != nullptr) {
        convertTypeType(ctx->interfaceCommonBodyDeclaration()->typeTypeOrVoid()->typeType(), method->returnTypeName);
    } else {
        method->returnTypeName->typeName.push_back(ctx->interfaceCommonBodyDeclaration()->typeTypeOrVoid()->VOID()->getText());
    }
    method->isVariableParameter = convertFormalParameters(ctx->interfaceCommonBodyDeclaration()->formalParameters(), method->parameters);
    convertTypeParameters(ctx->typeParameters(), method->typeParams);
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceMethodModifier(JavaParser::InterfaceMethodDeclarationContext* ctx, Method* method) {
    for (auto& modifier : ctx->interfaceMethodModifier()) {
        if (modifier->DEFAULT()) {
            method->flag |= Modifier::DEFAULT;
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertConstDeclaration(JavaParser::ConstDeclarationContext* ctx, VariableDeclaration* variableDeclaration) {
    convertTypeType(ctx->typeType(), &variableDeclaration->typeType);
    for (auto& constDeclarator : ctx->constantDeclarator()) {
        NameAndRelatedExp nameAndExp;
        convertConstDeclarator(constDeclarator, &nameAndExp);
        variableDeclaration->nameAndValueCount.push_back(nameAndExp);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertConstDeclarator(JavaParser::ConstantDeclaratorContext* ctx, NameAndRelatedExp* nameAndExp) {
    nameAndExp->name.push_back(ctx->identifier()->getText());
    convertVariableInitializerNoRecur(ctx->variableInitializer(), nameAndExp);
}

void AntlrNodeToSyntaxObjectConverter::convertMethodCallWithExplicitTypeArgument(JavaParser::PrimaryMethodCallWithExplicitTypeArgumentContext* ctx, NameAndRelatedExp* methodCall) {
    if (ctx->THIS() != nullptr) {
        methodCall->name.push_back(ctx->THIS()->getText());
        convertArguments(ctx->arguments(), methodCall);
    } else if (ctx->explicitGenericInvocationSuffix()->SUPER() != nullptr) {
        methodCall->name.push_back(ctx->explicitGenericInvocationSuffix()->SUPER()->getText());
        convertSuperSuffix(ctx->explicitGenericInvocationSuffix()->superSuffix(), methodCall);
    } else {
        methodCall->name.push_back(ctx->explicitGenericInvocationSuffix()->identifier()->getText());
        convertArguments(ctx->explicitGenericInvocationSuffix()->arguments(), methodCall);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationField(JavaParser::ClassBodyDeclarationContext* ctx, VariableDeclaration* variableDeclaration) {
    convertModifiers(ctx->modifier(), &variableDeclaration->flag);
    convertFieldDeclaration(ctx->memberDeclaration()->fieldDeclaration(), variableDeclaration);
}

void AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationMethod(JavaParser::ClassBodyDeclarationContext* ctx, Method* method) {
    convertModifiers(ctx->modifier(), &method->flag);
    if (ctx->memberDeclaration()->methodDeclaration() != nullptr) {
        convertMethodDeclaration(ctx->memberDeclaration()->methodDeclaration(), method);
    } else if (ctx->memberDeclaration()->constructorDeclaration() != nullptr) {
        convertConstructorDeclaration(ctx->memberDeclaration()->constructorDeclaration(), method);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertClassBodyDeclarationType(JavaParser::ClassBodyDeclarationContext* ctx, Type* type) {
    convertModifiers(ctx->modifier(), &type->flag);
    if (ctx->memberDeclaration()->classDeclaration() != nullptr) {
        convertClassDeclaration(ctx->memberDeclaration()->classDeclaration(), type);
    } else if (ctx->memberDeclaration()->interfaceDeclaration() != nullptr) {
        convertInterfaceDeclaration(ctx->memberDeclaration()->interfaceDeclaration(), type);
    } else if (ctx->memberDeclaration()->enumDeclaration() != nullptr) {
        convertEnumDeclaration(ctx->memberDeclaration()->enumDeclaration(), type);
    }
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationConst(JavaParser::InterfaceBodyDeclarationContext* ctx, VariableDeclaration* variableDeclaration) {
    convertModifiers(ctx->modifier(), &variableDeclaration->flag);
    convertConstDeclaration(ctx->interfaceMemberDeclaration()->constDeclaration(), variableDeclaration);
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationMethod(JavaParser::InterfaceBodyDeclarationContext* ctx, Method* method) {
    convertModifiers(ctx->modifier(), &method->flag);
    convertInterfaceMethodDeclaration(ctx->interfaceMemberDeclaration()->interfaceMethodDeclaration(), method);
}

void AntlrNodeToSyntaxObjectConverter::convertInterfaceBodyDeclarationType(JavaParser::InterfaceBodyDeclarationContext* ctx, Type* type) {
    convertModifiers(ctx->modifier(), &type->flag);
    if (ctx->interfaceMemberDeclaration()->classDeclaration() != nullptr) {
        convertClassDeclaration(ctx->interfaceMemberDeclaration()->classDeclaration(), type);
    } else if (ctx->interfaceMemberDeclaration()->interfaceDeclaration() != nullptr) {
        convertInterfaceDeclaration(ctx->interfaceMemberDeclaration()->interfaceDeclaration(), type);
    } else if (ctx->interfaceMemberDeclaration()->enumDeclaration() != nullptr) {
        convertEnumDeclaration(ctx->interfaceMemberDeclaration()->enumDeclaration(), type);
    }
}

bool AntlrNodeToSyntaxObjectConverter::convertFormalParameters(JavaParser::FormalParametersContext* ctx, list<FieldOrParameter*>& parameters) {
    bool variableParameter = false;
    if (ctx->formalParameterList() != nullptr) {
        for (auto* parameter : ctx->formalParameterList()->formalParameter()) {
            FieldOrParameter* p = new FieldOrParameter();
            convertFormalParameter(parameter, p);
            parameters.push_back(p);
        }
        if (ctx->formalParameterList()->lastFormalParameter()) {
            FieldOrParameter* p = new FieldOrParameter();
            convertLastFormalParameter(ctx->formalParameterList()->lastFormalParameter(), p);
            parameters.push_back(p);
            variableParameter = true;
        }
    }
    return variableParameter;
}

void AntlrNodeToSyntaxObjectConverter::convertTypeParameters(JavaParser::TypeParametersContext* ctx, list<TypeParam*>& typeParameters) {
    if (ctx) {
        for (auto& typeParamCtx : ctx->typeParameter()) {
            TypeParam* typeParam = new TypeParam();
            convertTypeParam(typeParamCtx, typeParam);
            typeParameters.push_back(typeParam);
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertTypeArguments(JavaParser::TypeArgumentsContext* ctx, vector<TypeName*>& typeArguments) {
    for (auto& typeArg : ctx->typeArgument()) {
        TypeName* typeName = new TypeName();
        if (typeArg->typeType()) {
            TypeName* typeName = new TypeName();
            convertTypeType(typeArg->typeType(), typeName);
            typeArguments.push_back(typeName);
        } else {
            typeName->typeName.push_back("Object");
            typeArguments.push_back(typeName);
        }
    }
}

void AntlrNodeToSyntaxObjectConverter::convertFormalParameter(JavaParser::FormalParameterContext* ctx, FieldOrParameter* parameter) {
    TypeName* typeName = new TypeName();
    convertTypeType(ctx->typeType(), typeName, ctx->variableModifier());
    parameter->typeName = typeName;
    parameter->name = ctx->variableDeclaratorId()->identifier()->getText();
    typeName->dim += ctx->variableDeclaratorId()->LBRACK().size();
}

void AntlrNodeToSyntaxObjectConverter::convertLastFormalParameter(JavaParser::LastFormalParameterContext* ctx, FieldOrParameter* parameter) {
    TypeName* typeName = new TypeName();
    convertTypeType(ctx->typeType(), typeName, ctx->variableModifier());
    parameter->typeName = typeName;
    parameter->name = ctx->variableDeclaratorId()->identifier()->getText();
    typeName->dim += ctx->variableDeclaratorId()->LBRACK().size();
}

void AntlrNodeToSyntaxObjectConverter::convertLambdaParameters(JavaParser::LambdaParametersContext* ctx, list<string>& paramName) {
    if (not ctx) {
        return;
    }
    for (auto& id : ctx->identifier()) {
        paramName.push_back(id->getText());
    }
    if (ctx->formalParameterList()) {
        for (auto* parameter : ctx->formalParameterList()->formalParameter()) {
            paramName.push_back(parameter->variableDeclaratorId()->identifier()->getText());
        }
    }
    if (ctx->lambdaLVTIList()) {
        for (auto* parameter : ctx->lambdaLVTIList()->lambdaLVTIParameter()) {
            paramName.push_back(parameter->identifier()->getText());
        }
    }
}

list<FieldOrParameter*> AntlrNodeToSyntaxObjectConverter::convertVariableObj(VariableDeclaration* variableDeclaration) {
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
