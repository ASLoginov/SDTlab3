#pragma once
#include "IMethod.h"
#include <vector>

class MethodCPP :
    public IMethod
{
    MethodCPP(const std::string& name, const std::string& returnType, Flags flags) :
        m_name(name), m_returnType(returnType) {
        if (m_flags & (ABSTRACT | FINAL)) m_flags |= VIRTUAL;
        if (m_flags & ABSTRACT & FINAL) m_flags ^= ABSTRACT | FINAL;
        if (m_flags & STATIC) {
            m_flags &= STATIC | VIRTUAL;
            if (m_flags & VIRTUAL) m_flags = 0;
        }
    }

    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }

    Flags getFlags() const { return m_flags; }

    std::string compile(unsigned int level = 0) const;

private:

    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

