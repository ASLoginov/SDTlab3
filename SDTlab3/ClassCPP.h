#pragma once
#include "IClass.h"
#include <vector>

class ClassCPP :
    public IClass
{
public:

    explicit ClassCPP(const std::string& name) : m_name(name) {
        m_fields.resize(3);
    }

    void add(const std::shared_ptr<Unit>& unit, Flags flags);

    std::string compile(unsigned int level = 0) const;

private:

    Flags m_flags = 0;
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    std::vector<Fields> m_fields;
};