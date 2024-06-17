#pragma once
#include "IClass.h"
#include <vector>

class ClassJava :
    public IClass
{
public:

    enum ClassModifier {
        PUBLIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2
    };

    explicit ClassJava(const std::string& name, Flags flags) :
        m_name(name) {}

    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0);

    std::string compile(unsigned int level = 0) const;

private:

    Flags m_flags = 0;
    std::string m_name;
    using Fields = std::vector<std::pair<Flags, std::shared_ptr<Unit>>>;
    Fields m_fields;
};

