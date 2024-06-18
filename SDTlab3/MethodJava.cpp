#include "MethodJava.h"

MethodJava::MethodJava(const std::string& name, const std::string& returnType, Flags flags) :
    m_name(name), m_returnType(returnType), m_flags(flags)
{
    if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
    if (m_flags & STATIC) {
        m_flags &= STATIC | VIRTUAL;
        if (m_flags & VIRTUAL) m_flags = 0;
    }
    m_flags &= 0b10101;
}

std::string MethodJava::compile(unsigned int level) const {
    std::string result;
    for (int i = 0; i < MODIFIERS.size(); i++) {
        if (m_flags & 1 << i) {
            result += MODIFIERS[i] + " ";
        }
    }
    result += m_returnType + " ";
    result += m_name + "()";
    if (m_flags & ABSTRACT) {
        result += ";\n";
        return result;
    }
    result += " {\n";
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
