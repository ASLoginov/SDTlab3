#pragma once
#include "SimpleClass.h"

class ClassCSharp :
    public SimpleClass
{
public:

    explicit ClassCSharp(const std::string& name, Flags flags = 0);

    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0);
};

