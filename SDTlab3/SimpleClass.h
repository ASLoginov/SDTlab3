#pragma once
#include "IClass.h"

class SimpleClass :
    public IClass
{
public:

    explicit SimpleClass(const std::string& name, Flags flags = 0) :
        m_name(name), m_flags(flags) {}

    std::string compile(unsigned int level = 0) const;

    ~SimpleClass() = 0;

protected:

    Flags m_flags = 0;
    std::string m_name;
    using Fields = std::vector<std::pair<Flags, std::shared_ptr<Unit>>>;
    Fields m_fields;
};

