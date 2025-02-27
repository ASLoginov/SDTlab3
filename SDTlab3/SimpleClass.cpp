#include "SimpleClass.h"

std::string SimpleClass::compile(unsigned int level) const {
    std::string modifier;
    for (int i = 0; i < MODIFIERS.size(); i++) {
        if (m_flags & 1 << i) {
            modifier += MODIFIERS[i] + " ";
        }
    }
    std::string result = modifier + "class " + m_name + " {\n\n";
    for (int i = 0; i < m_fields.size(); i++) {
        std::string mod;
        for (int j = 0; j < ACCESS_MODIFIERS.size(); j++) {
            if (m_fields[i].first & (1 << j)) {
                mod += ACCESS_MODIFIERS[j] + " ";
            }
        }
        result += generateShift(level + 1) + mod;
        result += m_fields[i].second->compile(level + 1);
        if (i < m_fields.size() - 1) result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}

SimpleClass::~SimpleClass() {}
