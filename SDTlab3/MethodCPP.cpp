#include "MethodCPP.h"

MethodCPP::MethodCPP(const std::string& name, const std::string& returnType, Flags flags) :
    m_name(name), m_returnType(returnType), m_flags(flags) {
    if (m_flags & (ABSTRACT | FINAL)) m_flags |= VIRTUAL;
    if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
    if (m_flags & STATIC) {
        m_flags &= STATIC | VIRTUAL;
        if (m_flags & VIRTUAL) m_flags = 0;
    }
}

std::string MethodCPP::compile(unsigned int level) const
{
    std::string result = generateShift(level);
    if (m_flags & STATIC) {
        result += "static ";
    }
    else if (m_flags & VIRTUAL) {
        result += "virtual ";
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if (m_flags & CONST) {
        result += " const";
    }
    if (m_flags & FINAL) {
        result += " final";
    }
    if (m_flags & ABSTRACT) {
        result += " = 0;\n";
        return result;
    }
    result += " {\n";
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
