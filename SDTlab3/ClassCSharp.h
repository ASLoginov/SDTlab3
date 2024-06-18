#pragma once
#include "IClass.h"
#include <vector>

class ClassCSharp :
    public IClass
{
public:

    explicit ClassCSharp(const std::string& name, Flags flags) : m_name(name) {
        flags &= ABSTRACT;
        m_flags = flags;
    }

    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0);


    std::string compile(unsigned int level = 0) const;

private:

    Flags m_flags = 0;
    std::string m_name;
    using Fields = std::vector<std::pair<Flags, std::shared_ptr<Unit>>>;
    Fields m_fields;
};

