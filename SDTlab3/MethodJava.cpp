#include "MethodJava.h"

const std::vector<std::string> MethodJava::METHOD_MODIFIERS =
{ "public", "private", "protected", "static", "final", "abstract" };

std::string MethodJava::compile(unsigned int level) const {
    std::string result = generateShift(level);
    std::string modifier;
    for (int i = 0; i < METHOD_MODIFIERS.size(); i++) {
        if (m_flags & 1 << i) {
            modifier += METHOD_MODIFIERS[i] + " ";
        }
    }
    result += modifier;
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
