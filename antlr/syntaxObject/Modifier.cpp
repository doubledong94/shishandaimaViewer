#include "antlr/syntaxObject/Modifier.h"


const int Modifier::PUBLIC = 0x00000001;
const int Modifier::PRIVATE = 0x00000002;
const int Modifier::PROTECTED = 0x00000004;
const int Modifier::STATIC = 0x00000008;

const int Modifier::FINAL = 0x00000010;
const int Modifier::SYNCHRONIZED = 0x00000020;
const int Modifier::VOLATILE = 0x00000040;
const int Modifier::TRANSIENT = 0x00000080;

const int Modifier::NATIVE = 0x00000100;
const int Modifier::VARARGS = 0x00000200;
const int Modifier::ABSTRACT = 0x00000400;
const int Modifier::STRICT = 0x00000800;

const int Modifier::SYNTHETIC = 0x00001000;
const int Modifier::ANNOTATION = 0x00002000;
const int Modifier::BRIDGE = 0x00004000;
const int Modifier::MANDATED = 0x00008000;

const int Modifier::CLASS = 0x00010000;
const int Modifier::INTERFACE = 0x00020000;
const int Modifier::ENUM = 0x00040000;
const int Modifier::DEFAULT = 0x00080000;

const int Modifier::CLASS_MODIFIERS = PUBLIC | PROTECTED | PRIVATE | ABSTRACT | STATIC | FINAL | STRICT;

const int Modifier::INTERFACE_MODIFIERS = PUBLIC | PROTECTED | PRIVATE | ABSTRACT | STATIC | STRICT;

const int Modifier::CONSTRUCTOR_MODIFIERS = PUBLIC | PROTECTED | PRIVATE;

const int Modifier::METHOD_MODIFIERS = PUBLIC | PROTECTED | PRIVATE | ABSTRACT | STATIC | FINAL | SYNCHRONIZED | NATIVE | STRICT;

const int Modifier::FIELD_MODIFIERS = PUBLIC | PROTECTED | PRIVATE | STATIC | FINAL | TRANSIENT | VOLATILE;

const int Modifier::PARAMETER_MODIFIERS = FINAL;

const int Modifier::ACCESS_MODIFIERS = PUBLIC | PROTECTED | PRIVATE;

bool Modifier::isPublic(unsigned int mod) {
    return (mod & PUBLIC) != 0;
}

bool Modifier::isPrivate(unsigned int mod) {
    return (mod & PRIVATE) != 0;
}

bool Modifier::isProtected(unsigned int mod) {
    return (mod & PROTECTED) != 0;
}

bool Modifier::isStatic(unsigned int mod) {
    return (mod & STATIC) != 0;
}

bool Modifier::isFinal(unsigned int mod) {
    return (mod & FINAL) != 0;
}

bool Modifier::isSynchronized(unsigned int mod) {
    return (mod & SYNCHRONIZED) != 0;
}

bool Modifier::isVolatile(unsigned int mod) {
    return (mod & VOLATILE) != 0;
}

bool Modifier::isTransient(unsigned int mod) {
    return (mod & TRANSIENT) != 0;
}

bool Modifier::isNative(unsigned int mod) {
    return (mod & NATIVE) != 0;
}

bool Modifier::isAbstract(unsigned int mod) {
    return (mod & ABSTRACT) != 0;
}

bool Modifier::isStrict(unsigned int mod) {
    return (mod & STRICT) != 0;
}

bool Modifier::isClassType(unsigned int mod) {
    return (mod & CLASS) != 0;
}

bool Modifier::isInterfaceType(unsigned int mod) {
    return (mod & INTERFACE) != 0;
}

bool Modifier::isEnumType(unsigned int mod) {
    return (mod & ENUM) != 0;
}

bool Modifier::isDefault(unsigned int mod) {
    return (mod & DEFAULT) != 0;
}
