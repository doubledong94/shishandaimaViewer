#ifndef JPARSER_MODIFIER_H
#define JPARSER_MODIFIER_H


class Modifier {
public:
    static bool isPublic(unsigned int mod);

    static bool isPrivate(unsigned int mod);

    static bool isProtected(unsigned int mod);

    static bool isStatic(unsigned int mod);

    static bool isFinal(unsigned int mod);

    static bool isSynchronized(unsigned int mod);

    static bool isVolatile(unsigned int mod);

    static bool isTransient(unsigned int mod);

    static bool isNative(unsigned int mod);

    static bool isAbstract(unsigned int mod);

    static bool isStrict(unsigned int mod);

    static bool isClassType(unsigned int mod);

    static bool isInterfaceType(unsigned int mod);

    static bool isEnumType(unsigned int mod);

    static bool isDefault(unsigned int mod);

    const static int PUBLIC;
    const static int PRIVATE;
    const static int PROTECTED;
    const static int STATIC;
    const static int FINAL;
    const static int SYNCHRONIZED;
    const static int VOLATILE;
    const static int TRANSIENT;
    const static int NATIVE;
    const static int INTERFACE;
    const static int ABSTRACT;
    const static int STRICT;

    const static int BRIDGE;
    const static int VARARGS;
    const static int SYNTHETIC;
    const static int ANNOTATION;
    const static int ENUM;
    const static int MANDATED;
    const static int CLASS;

    const static int CLASS_MODIFIERS;
    const static int INTERFACE_MODIFIERS;
    const static int CONSTRUCTOR_MODIFIERS;
    const static int METHOD_MODIFIERS;
    const static int FIELD_MODIFIERS;
    const static int PARAMETER_MODIFIERS;
    const static int ACCESS_MODIFIERS;
    const static int DEFAULT;

private:
    Modifier() {}
};

#endif //JPARSER_MODIFIER_H
