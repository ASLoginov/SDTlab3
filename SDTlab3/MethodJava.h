#pragma once
#include "IMethod.h"
#include <vector>

class MethodJava :
    public IMethod
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
        if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
        if (m_flags & STATIC) {
            m_flags &= STATIC | VIRTUAL;
            if (m_flags & VIRTUAL) m_flags = 0;
        }
        m_flags &= 0b10101;
    }

    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const;

    Flags getFlags() const { return m_flags; }

private:

    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

