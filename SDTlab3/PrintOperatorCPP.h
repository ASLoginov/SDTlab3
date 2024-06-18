#pragma once
#include "IPrintOperator.h"

class PrintOperatorCPP :
    public IPrintOperator
{

public:

    void add(const std::shared_ptr<Unit>&, Flags = 0) {}

    explicit PrintOperatorCPP(const std::string& text) : m_text(text) {}

    std::string compile(unsigned int level = 0) const {
        return generateShift(level) + "printf( \"" + m_text + "\" );\n";
    }

private:

    std::string m_text;
};

