#pragma once
#include "IMethod.h"
#include <vector>

class MethodCSharp :
    public IMethod
{
public:

    MethodCSharp(const std::string& name, const std::string& returnType, Flags flags);

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

