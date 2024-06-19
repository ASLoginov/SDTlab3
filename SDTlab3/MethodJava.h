#pragma once
#include "SimpleMethod.h"

class MethodJava :
    public SimpleMethod
{
public:
    
    MethodJava(const std::string& name, const std::string& returnType, Flags flags);
};

