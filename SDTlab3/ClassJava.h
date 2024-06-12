#pragma once
#include "Unit.h"
#include <vector>

class ClassJava :
    public Unit
{
public:

    enum ClassModifier {
        PUBLIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1 << 2
    };

    static const std::vector<std::string> CLASS_MODIFIERS;

    explicit ClassJava(const std::string& name, Flags flags) :
        m_name(name), m_flags(flags)
    {
        if (m_flags & FINAL && m_flags & ABSTRACT) {
            throw std::runtime_error("Modifiers conflict");
        }
    }

    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0) {
        m_fields.push_back(unit);
    }

    std::string compile(unsigned int level = 0) const;

private:

    Flags m_flags;
    std::string m_name;
    using Fields = std::vector<std::shared_ptr<Unit>>;
    Fields m_fields;
};

