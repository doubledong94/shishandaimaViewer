#ifndef JPARSER_HEADERENTERVISITOR_H
#define JPARSER_HEADERENTERVISITOR_H

/** This is the second phase of Enter, in which classes are completed
 *  by resolving their headers and entering their members in the into
 *  the class scope. See Enter for an overall overview.
 *
 *  - ImportPhase: shallow pass through imports, adds information about imports
 *                 the NamedImportScope and StarImportScope, but avoids queries
 *                 about class hierarchy.
 *  - HierarchyPhase: resolves the supertypes of the given class. Does not handle
 *                    type parameters of the class or type argument of the supertypes.
 *  - HeaderPhase: finishes analysis of the header of the given class by resolving
 *                 type parameters, attributing supertypes including type arguments
 *                 and scheduling full annotation attribution. This phase also adds
 *                 a synthetic default constructor if needed and synthetic "this" field.
 *  - MembersPhase: resolves headers for fields, methods and constructors in the given class.
 *                  Also generates synthetic enum members.
 *
 */


namespace Header {
    class PhaseBaseClass {
    public:
        string currentFilePath;
        string package = "";
        list<string> typeNameStack;
        list<string> typeKeyStack;

        void visitCompilationUnit(CompilationUnit* compilationUnit);

        virtual void visitType(Type* type);

        void pushTypeStack(const string& typeName);

        void popTypeStack();

        void recurVisitInnerType(Type* type);

        void reset();
    };

    class EnterClassPhase :PhaseBaseClass {
    public:
        set<string> duplicateTypeFile;
        void run();
        // prepare ClassScopeAndEnv (just inner info) for :
        // "resolving inner class in bounds of type parameter"
        // "inner class in type arguments of super types"
        // "inner class of other class (this is why this function is in FirstVisitor) in bounds and type arguments and extends"
        // in  HierarchyAndMemberVisitor
        void visitType(Type* type) override;
    };

    class SuperRelationUnresolved {
    public:
        // type: 1 for extends, 2 for implements
        int type;
        TypeInfo* typeInfo;
        TypeName* superTypeName;
    };

    class HierarchyPhase {
    public:
        static set<SuperRelationUnresolved*> superRelationUnresolved;
        // return true if superRelationUnresolved size change, false otherwise
        static bool finishUnresolved();

        static void resolveHierarchy();

        static void addOverrideInfo();

        static void addOverMethod2TypeKey(TypeInfo* typeInfo, MethodInfo* methodInfo);
    };

    class MemeberPhase :PhaseBaseClass {
        list<TypeInfo*> typeInfoStack;
    public:
        void run();
        void visitType(Type* type) override;
        void visitEnum(TypeInfo* typeInfo, string& enumConst);
        void addFieldInfo(FieldOrParameter* field);
        void addMethodInfo(Method* method, bool isConstructor);
    };

}
#endif //JPARSER_HEADERENTERVISITOR_H
