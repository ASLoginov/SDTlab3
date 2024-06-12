#pragma once
#include "Unit.h"
class PrintOperatorCSharp :
    public Unit
{
public:

    explicit PrintOperatorCSharp(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "Console.Write( \"" + m_text + "\" );\n";
    }

private:

    std::string m_text;
};

