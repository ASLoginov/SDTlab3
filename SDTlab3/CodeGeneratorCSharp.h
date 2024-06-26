#pragma once
#include "ICodeGenerator.h"
#include "ClassCSharp.h"
#include "MethodCSharp.h"
#include "PrintOperatorCSharp.h"

class CodeGeneratorCSharp : public ICodeGenerator {
public:
	std::shared_ptr<IClass> getClass(const std::string& name, Unit::Flags flags) const {
		return std::make_shared<ClassCSharp>(name);
	}

	std::shared_ptr<IMethod> getMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
		return std::make_shared<MethodCSharp>(name, returnType, flags);
	}

	std::shared_ptr<IPrintOperator> getPrintOperator(const std::string& text) const {
		return std::make_shared<PrintOperatorCSharp>(text);
	}
};