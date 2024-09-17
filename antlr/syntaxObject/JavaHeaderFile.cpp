#include "util/util.h"
#include "antlr/syntaxObject/JavaHeaderFile.h"

void TypeName::toFile(ofstream& f) {
    f << dim << "\n";
    f << joinList(typeName, ".") << "\n";
    f << typeArgs.size() << "\n";
    for (auto& typeArg : typeArgs) {
        typeArg->toFile(f);
    }
}

void TypeName::fromFile(ifstream& f) {
    dim = getInt(f);
    string s;
    getline(f, s);
    splitStr(s, ".", typeName);
    int typeArgCount = getInt(f);
    for (int i = 0;i < typeArgCount;i++) {
        TypeName* typeArg = new TypeName();
        typeArg->fromFile(f);
        typeArgs.push_back(typeArg);
    }
}

void TypeName::copy(TypeName* origin) {
    dim = origin->dim;
    typeName = origin->typeName;
    typeArgs = origin->typeArgs;
}

void FieldOrParameter::toFile(ofstream& f) {
    f << flag << "\n";
    f << name << "\n";
    typeName->toFile(f);
}

void FieldOrParameter::fromFile(ifstream& f) {
    flag = getUInt(f);
    getline(f, name);
    typeName = new TypeName();
    typeName->fromFile(f);
}

void TypeParam::toFile(ofstream& f) {
    f << name << "\n";
    f << bounds.size() << "\n";
    for (auto& bound : bounds) {
        bound->toFile(f);
    }
}

void TypeParam::fromFile(ifstream& f) {
    getline(f, name);
    int boundCount = getInt(f);
    for (int i = 0;i < boundCount;i++) {
        TypeName* bound = new TypeName();
        bound->fromFile(f);
        bounds.push_back(bound);
    }
}

void Method::toFile(ofstream& f) {
    f << flag << "\n";
    f << name << "\n";
    returnTypeName->toFile(f);
    f << parameters.size() << "\n";
    FOR_EACH_ITEM(parameters,
        item->toFile(f);
    );
    f << typeParams.size() << "\n";
    FOR_EACH_ITEM(typeParams,
        item->toFile(f);
    );
    f << (isVariableParameter ? 1 : 0) << "\n";
}

void Method::fromFile(ifstream& f) {
    flag = getUInt(f);
    getline(f, name);
    returnTypeName = new TypeName();
    returnTypeName->fromFile(f);
    int count = getInt(f);
    for (int i = 0;i < count;i++) {
        FieldOrParameter* param = new FieldOrParameter();
        param->fromFile(f);
        parameters.push_back(param);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        TypeParam* typeParam = new TypeParam();
        typeParam->fromFile(f);
        typeParams.push_back(typeParam);
    }
    isVariableParameter = getInt(f);
}

void Type::toFile(ofstream& f) {
    f << flag << "\n";
    f << name << "\n";
    f << extendsTypeNames.size() << "\n";
    FOR_EACH_ITEM(extendsTypeNames,
        item->toFile(f);
    );
    f << implementsTypeNames.size() << "\n";
    FOR_EACH_ITEM(implementsTypeNames,
        item->toFile(f);
    );
    f << fields.size() << "\n";
    FOR_EACH_ITEM(fields,
        item->toFile(f);
    );
    f << constructors.size() << "\n";
    FOR_EACH_ITEM(constructors,
        item->toFile(f);
    );
    f << methods.size() << "\n";
    FOR_EACH_ITEM(methods,
        item->toFile(f);
    );
    f << innerTypes.size() << "\n";
    FOR_EACH_ITEM(innerTypes,
        item->toFile(f);
    );
    f << typeParams.size() << "\n";
    FOR_EACH_ITEM(typeParams,
        item->toFile(f);
    );
    f << enumConstants.size() << "\n";
    FOR_EACH_ITEM(enumConstants,
        f << item << "\n";
    );
}

void Type::fromFile(ifstream& f) {
    flag = getUInt(f);
    getline(f, name);
    int count = getInt(f);
    for (int i = 0;i < count;i++) {
        TypeName* ext = new TypeName();
        ext->fromFile(f);
        extendsTypeNames.push_back(ext);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        TypeName* impl = new TypeName();
        impl->fromFile(f);
        implementsTypeNames.push_back(impl);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        FieldOrParameter* field = new FieldOrParameter();
        field->fromFile(f);
        fields.push_back(field);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        Method* conostructor = new Method();
        conostructor->fromFile(f);
        constructors.push_back(conostructor);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        Method* method = new Method();
        method->fromFile(f);
        methods.push_back(method);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        Type* type = new Type();
        type->fromFile(f);
        innerTypes.push_back(type);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        TypeParam* typeParam = new TypeParam();
        typeParam->fromFile(f);
        typeParams.push_back(typeParam);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        string s;
        getline(f, s);
        enumConstants.push_back(s);
    }
}

void CompilationUnit::toFile(ofstream& f) {
    f << package << "\n";
    f << importedTypes.size() << "\n";
    FOR_EACH_ITEM(importedTypes,
        f << item << "\n";
    );
    f << importedPackageOrType.size() << "\n";
    FOR_EACH_ITEM(importedPackageOrType,
        f << item << "\n";
    );
    f << staticImported.size() << "\n";
    FOR_EACH_ITEM(staticImported,
        f << item << "\n";
    );
    f << starStaticImported.size() << "\n";
    FOR_EACH_ITEM(starStaticImported,
        f << item << "\n";
    );
    f << types.size() << "\n";
    FOR_EACH_ITEM(types,
        item->toFile(f);
    );
}

void CompilationUnit::fromFile(ifstream& f) {
    std::getline(f, package);
    int count = getInt(f);
    for (int i = 0;i < count;i++) {
        string s;
        getline(f, s);
        importedTypes.push_back(s);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        string s;
        getline(f, s);
        importedPackageOrType.push_back(s);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        string s;
        getline(f, s);
        staticImported.push_back(s);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        string s;
        getline(f, s);
        starStaticImported.push_back(s);
    }
    count = getInt(f);
    for (int i = 0;i < count;i++) {
        Type* type = new Type();
        type->fromFile(f);
        types.push_back(type);
    }
}

int Serializable::getInt(ifstream& f) {
    string countStr;
    std::getline(f, countStr);
    return stoi(countStr);
}

unsigned Serializable::getUInt(ifstream& f) {
    string countStr;
    std::getline(f, countStr);
    return stoul(countStr);
}
