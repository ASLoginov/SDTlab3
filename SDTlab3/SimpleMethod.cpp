#include "SimpleMethod.h"

SimpleMethod::SimpleMethod(const std::string& name, const std::string& returnType, Flags flags) :
	m_name(name), m_returnType(returnType), m_flags(flags) {}

std::string SimpleMethod::compile(unsigned int level) const {
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

SimpleMethod::~SimpleMethod() {}

