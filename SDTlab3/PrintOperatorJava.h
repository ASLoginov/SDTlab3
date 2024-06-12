#pragma once
#include "Unit.h"
class PrintOperatorJava :
    public Unit
{
public:

    explicit PrintOperatorJava(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "System.out.printf( \"" + m_text + "\" );\n";
    }

private:

    std::string m_text;
};

