class TypeCheckAndInference {
public:
    static bool isAssignable(TypeInfo* typeInfo, TypeInfo* superTypeInfo);

    static bool isNumberAssignable(TypeInfo* typeInfo, TypeInfo* superTypeInfo);

    static bool methodParamCountCheck(MethodInfo* methodInfo, int paramCount);

    static MethodInfo* findBestMethod(list<MethodInfo*>& methodInfos, vector<ResolvingItem*>& arguments);
};

