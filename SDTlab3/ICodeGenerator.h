#pragma once
#include "IClass.h"
#include "IMethod.h"
#include "IPrintOperator.h"

class ICodeGenerator {
public:
	virtual ~ICodeGenerator() {};
	virtual std::shared_ptr<IClass> getClass(const std::string& name, Unit::Flags flags = 0) const = 0;
	virtual std::shared_ptr<IMethod> getMethod(const std::string& name, const std::string& returnType, Unit::Flags flags = 0) const = 0;
	virtual std::shared_ptr<IPrintOperator> getPrintOperator(const std::string& text) const = 0;
};
