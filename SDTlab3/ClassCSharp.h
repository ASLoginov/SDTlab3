#pragma once
#include "Unit.h"
#include <vector>

class ClassCSharp :
    public Unit
{
public:

    enum ClassModifier {
        PUBLIC = 1,
        FILE = 1 << 1,
        INTERNAL = 1 << 2,
        ABSTRACT = 1 << 3,
        SEALED = 1 << 4
    };

    static const std::vector<std::string> CLASS_MODIFIERS;

    explicit ClassCSharp(const std::string& name, Flags flags) :
        m_name(name), m_flags(flags)
    {
        if (m_flags & SEALED && m_flags & ABSTRACT ||
            (m_flags & PUBLIC) + ((m_flags & FILE) >> 1) + ((m_flags & INTERNAL) >> 2) > 1) {
            throw std::runtime_error("Midifiers conflict");
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

