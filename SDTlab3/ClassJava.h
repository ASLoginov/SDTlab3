#pragma once
#include "IClass.h"
#include <vector>

class ClassJava :
    public IClass
{
public:

    explicit ClassJava(const std::string& name, Flags flags = 0) : m_name(name) {
        flags &= ABSTRACT | FINAL;
        if (flags & ABSTRACT && flags & FINAL) flags = 0;
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

