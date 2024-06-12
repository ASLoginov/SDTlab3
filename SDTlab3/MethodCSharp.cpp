#include "MethodCSharp.h"

const std::vector<std::string> MethodCSharp::METHOD_MODIFIERS =
{ "public", "private", "internal", "protected", "static", "virtual", "sealed", "override" };

std::string MethodCSharp::compile(unsigned int level) const
{
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
    result += " {\n";
    for (const auto& b : m_body) {
        result += b->compile(level + 1);
    }
    result += generateShift(level) + "}\n";
    return result;
}
