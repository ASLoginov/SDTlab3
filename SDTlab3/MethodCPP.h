#pragma once
#include "SimpleMethod.h"

class MethodCPP :
    public SimpleMethod
{
public:

    MethodCPP(const std::string& name, const std::string& returnType, Flags flags);

    std::string compile(unsigned int level = 0) const;
};

