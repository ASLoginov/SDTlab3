#include "ClassCSharp.h"
#include "MethodCSharp.h"

void ClassCSharp::add(const std::shared_ptr<Unit>& unit, Flags flags) {
    flags &= 0b1111;
    if (!(flags & PROTECTED)) {
        if ((flags & PUBLIC) + ((flags & PRIVATE) >> 2) + ((flags & INTERNAL) >> 3) > 1) flags = 0;
    }
    else {
        if (flags & PUBLIC) flags = 0;
        else {
            if (flags & PRIVATE && flags & INTERNAL) flags ^= PRIVATE;
        }
    }
    m_fields.push_back({ flags, unit });
    MethodCSharp* m = dynamic_cast<MethodCSharp*>(unit.get());
    if (m) {
        if (m->getFlags() & ABSTRACT) {
            m_flags |= ABSTRACT;
        }
    }
}

std::string ClassCSharp::compile(unsigned int level) const {
    std::string modifier;
    for (int i = 0; i < MODIFIERS.size(); i++) {
        if (m_flags & 1 << i) {
            modifier += MODIFIERS[i] + " ";
        }
    }
    std::string result = modifier + "class " + m_name + " {\n\n";
    for (int i = 0; i < m_fields.size(); i++) {
        std::string mod;
        for (int j = 0; i < ACCESS_MODIFIERS.size(); i++) {
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
