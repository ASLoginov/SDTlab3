#include <iostream>
#include "CodeGeneratorCPP.h"
#include "CodeGeneratorJava.h"
#include "CodeGeneratorCSharp.h"


std::string generateProgram(const ICodeGenerator* generator) {
	auto myClass = generator->getClass("MyClass");
	myClass->add(generator->getMethod("testFunc1", "void", 0), IClass::PROTECTED);
	myClass->add(generator->getMethod("testFunc2", "void", Unit::STATIC), IClass::PRIVATE);
	myClass->add(generator->getMethod("testFunc3", "void", Unit::VIRTUAL | Unit::CONST | Unit::FINAL), IClass::PUBLIC);
	myClass->add(generator->getMethod("testFunc4", "void", Unit::ABSTRACT), IClass::PUBLIC);
	auto method = generator->getMethod("testFunc5", "void", Unit::STATIC);
	method->add(generator->getPrintOperator(R"(Hello, world!\n)"));
	myClass->add(method, IClass::PROTECTED);
	return myClass->compile();
}

int main() {

	std::vector<std::shared_ptr<ICodeGenerator>> generators;
	generators.push_back(std::make_shared<CodeGeneratorCPP>());
	generators.push_back(std::make_shared<CodeGeneratorJava>());
	generators.push_back(std::make_shared<CodeGeneratorCSharp>());

	for (auto& generator : generators) {
		std::cout << generateProgram(generator.get()) << std::endl << std::endl;
	}

	return 0;
}