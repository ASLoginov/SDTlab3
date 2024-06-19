#include "MethodCSharp.h"

MethodCSharp::MethodCSharp(const std::string& name, const std::string& returnType, Flags flags) :
    SimpleMethod(name, returnType, flags)
{
    if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
    if (flags & ABSTRACT) m_flags &= ~VIRTUAL;
    m_flags &= 0b111;
    if (m_flags & STATIC) {
        m_flags &= STATIC | VIRTUAL;
        if (m_flags & VIRTUAL) m_flags = 0;
    }
}
