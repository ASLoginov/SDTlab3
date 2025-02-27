#pragma once
#include "IMethod.h"

class SimpleMethod :
    public IMethod
{
public:

    SimpleMethod(const std::string& name, const std::string& returnType, Flags flags);

    void add(const std::shared_ptr<Unit>& unit, Flags /* flags */ = 0) {
        m_body.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const;
    Flags getFlags() const { return m_flags; }

    ~SimpleMethod() = 0;

protected:

    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector<std::shared_ptr<Unit>> m_body;
};

