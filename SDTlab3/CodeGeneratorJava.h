#pragma once
#include "ICodeGenerator.h"
#include "ClassJava.h"
#include "MethodJava.h"
#include "PrintOperatorJava.h"

class CodeGeneratorJava : public ICodeGenerator {
public:
	std::shared_ptr<IClass> getClass(const std::string& name, Unit::Flags flags) const {
		return std::make_shared<ClassJava>(name);
	}

	std::shared_ptr<IMethod> getMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
		return std::make_shared<MethodJava>(name, returnType, flags);
	}

	std::shared_ptr<IPrintOperator> getPrintOperator(const std::string& text) const {
		return std::make_shared<PrintOperatorJava>(text);
	}
};
