#include "ClassJava.h"

const std::vector<std::string> ClassJava::CLASS_MODIFIERS = { "public", "final", "abstract" };

std::string ClassJava::compile(unsigned int level) const {
    std::string modifier;
    for (int i = 0; i < CLASS_MODIFIERS.size(); i++) {
        if (m_flags & 1 << i) {
            modifier += CLASS_MODIFIERS[i] + " ";
        }
    }
    std::string result = generateShift(level) + modifier + "class " + m_name + " {\n";
    for (const auto& field : m_fields) {
        result += field->compile(level + 1);
    }
    result += "\n";
    result += generateShift(level) + "};\n";
    return result;
}
