#pragma once
#include "SimpleClass.h"

class ClassJava :
    public SimpleClass
{
public:

    explicit ClassJava(const std::string& name, Flags flags = 0);

    void add(const std::shared_ptr<Unit>& unit, Flags flags = 0);
};

