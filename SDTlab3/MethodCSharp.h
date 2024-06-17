#pragma once
#include "IMethod.h"
#include <vector>

class MethodCSharp :
    public IMethod
{
public:
    enum MethodModifier {
        PUBLIC = 1,
        PRIVATE = 1 << 1,
        INTERNAL = 1 << 2,
        PROTECTED = 1 << 3,
        STATIC = 1 << 4,
        VIRTUAL = 1 << 5,
        SEALED = 1 << 6,
        OVERRIDE = 1 << 7
    };

    static const std::vector<std::string> METHOD_MODIFIERS;

    MethodCSharp(const std::string& name, const std::string& returnType, Flags flags) :
        m_name(name), m_returnType(returnType), m_flags(flags)
    {
        if ((m_flags & PUBLIC) + ((m_flags & PRIVATE) >> 1) + ((m_flags & INTERNAL) >> 2) > 1 ||
            m_flags & PROTECTED && !(m_flags & PRIVATE || m_flags & INTERNAL) ||
            (m_flags & SEALED || m_flags & OVERRIDE) && m_flags & VIRTUAL ||
            m_flags & SEALED && !(m_flags & OVERRIDE)) {
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

