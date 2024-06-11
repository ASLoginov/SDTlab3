#pragma once
#include "Unit.h"
class PrintOperatorCPP :
    public Unit
{

public:

    explicit PrintOperatorCPP(const std::string& text) : m_text(text) { }
    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

private:

    std::string m_text;
};

