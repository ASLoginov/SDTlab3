#pragma once
#include "IPrintOperator.h"

class PrintOperatorCPP :
    public IPrintOperator
{

public:

    explicit PrintOperatorCPP(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

private:
    void add(const std::shared_ptr<Unit>&, Flags = 0) {}
    std::string m_text;
};

