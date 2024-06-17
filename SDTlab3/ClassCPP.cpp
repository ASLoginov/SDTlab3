#include "ClassCPP.h"

void ClassCPP::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    int accessModifier = 2;
    if (flags & PROTECTED) accessModifier = 1;
    if (flags & PUBLIC) accessModifier = 0;
    m_fields[accessModifier].push_back(unit);
}

std::string ClassCPP::compile(unsigned int level) const {
    std::string result = generateShift(level) + "class " + m_name + " {\n\n";
    for (size_t i = 0; i < 3; ++i) {
        if (m_fields[i].empty()) {
            continue;
        }
        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i]) {
            result += f->compile(level + 1);
        }
        if (i < 2) result += "\n";
    }
    result += generateShift(level) + "};\n";
    return result;
}
