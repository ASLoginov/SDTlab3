#include "MethodJava.h"

MethodJava::MethodJava(const std::string& name, const std::string& returnType, Flags flags) :
    SimpleMethod(name, returnType, flags)
{
    if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
    if (m_flags & STATIC) {
        m_flags &= STATIC | VIRTUAL;
        if (m_flags & VIRTUAL) m_flags = 0;
    }
    m_flags &= 0b10101;
}
