#pragma once
#include "Unit.h"
#include <vector>

class MethodJava :
    public Unit
{
public:
    enum MethodModifier {
        PUBLIC = 1,
        PRIVATE = 1 << 1,
        PROTECTED = 1 << 2,
        STATIC = 1 << 3,
        FINAL = 1 << 4,
        ABSTRACT = 1 << 5
    };

    static const std::vector<std::string> METHOD_MODIFIERS;

    MethodJava(const std::string& name, const std::string& returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags)
    {
        if (m_flags & FINAL && m_flags & ABSTRACT ||
            (m_flags & PUBLIC) + ((m_flags & PRIVATE) >> 1) + ((m_flags & PROTECTED) >> 2) > 1) {
            throw std::runtime_error("Modifiers conflict");
        }
    }

    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const;

private:

    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

