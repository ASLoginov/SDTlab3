#pragma once

#include "Unit.h"

class IMethod : public Unit {
public:
	virtual Flags getFlags() const = 0;
};