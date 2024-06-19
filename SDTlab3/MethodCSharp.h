#pragma once
#include "SimpleMethod.h"

class MethodCSharp :
    public SimpleMethod
{
public:

    MethodCSharp(const std::string& name, const std::string& returnType, Flags flags);
};

