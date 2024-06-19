#pragma once

#include "Unit.h"

class IClass : public Unit {

public:

    enum AccessModifier {
        PUBLIC = 1,
        PROTECTED = 1 << 1,
        PRIVATE = 1 << 2,
        INTERNAL = 1 << 3
    };

    static const std::vector<std::string> ACCESS_MODIFIERS;
};
