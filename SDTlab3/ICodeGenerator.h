#pragma once
#include "Unit.h"

class ICodeGenerator {
public:
	virtual ~ICodeGenerator() {};
	virtual std::shared_ptr<Unit> getClass(const std::string& name, Unit::Flags flags = 0) const = 0;
	virtual std::shared_ptr<Unit> getMethod(const std::string& name, const std::string& returnType, Unit::Flags flags = 0) const = 0;
	virtual std::shared_ptr<Unit> getPrintOperator(const std::string& text) const = 0;
};
