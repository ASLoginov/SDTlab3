#pragma once
#include "ICodeGenerator.h"
#include "ClassCPP.h"
#include "MethodCPP.h"
#include "PrintOperatorCPP.h"

class CodeGeneratorCPP : public ICodeGenerator {
public:
	std::shared_ptr<IClass> getClass(const std::string& name, Unit::Flags flags) const {
		return std::make_shared<ClassCPP>(name);
	}

	std::shared_ptr<IMethod> getMethod(const std::string& name, const std::string& returnType, Unit::Flags flags) const {
		return std::make_shared<MethodCPP>(name, returnType, flags);
	}

	std::shared_ptr<IPrintOperator> getPrintOperator(const std::string& text) const {
		return std::make_shared<PrintOperatorCPP>(text);
	}
};
