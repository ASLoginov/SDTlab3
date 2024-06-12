#include <iostream>
#include "CodeGeneratorCPP.h"
#include "CodeGeneratorJava.h"
#include "CodeGeneratorCSharp.h"

std::string generateProgramCPP() {
	std::shared_ptr<ICodeGenerator> generator = std::make_shared<CodeGeneratorCPP>();
	auto myClass = generator->getClass("MyClass");
	myClass->add(generator->getMethod("testFunc1", "void", 0), ClassCPP::PUBLIC);
	myClass->add(generator->getMethod("testFunc2", "void", MethodCPP::STATIC), ClassCPP::PRIVATE);
	myClass->add(generator->getMethod("testFunc3", "void", MethodCPP::VIRTUAL | MethodCPP::CONST), ClassCPP::PUBLIC);
	auto method = generator->getMethod("testFunc4", "void", MethodCPP::STATIC);
	method->add(generator->getPrintOperator(R"(Hello, world!\n)"));
	myClass->add(method, ClassCPP::PROTECTED);
	return myClass->compile();
}

std::string generateProgramJava() {
	std::shared_ptr<ICodeGenerator> generator = std::make_shared<CodeGeneratorJava>();
	auto myClass = generator->getClass("MyClass", ClassJava::PUBLIC | ClassJava::ABSTRACT);
	myClass->add(generator->getMethod("testFunc1", "void", MethodJava::PUBLIC));
	myClass->add(generator->getMethod("testFunc2", "void", MethodJava::PRIVATE | MethodJava::STATIC));
	myClass->add(generator->getMethod("testFunc3", "void", MethodJava::PUBLIC | MethodJava::ABSTRACT));
	auto method = generator->getMethod("testFunc4", "void", MethodJava::PROTECTED | MethodJava::STATIC);
	method->add(generator->getPrintOperator(R"(Hello, world!\n)"));
	myClass->add(method);
	return myClass->compile();
}

std::string generateProgramCSharp() {
	std::shared_ptr<ICodeGenerator> generator = std::make_shared<CodeGeneratorCSharp>();
	auto myClass = generator->getClass("MyClass", ClassCSharp::FILE);
	myClass->add(generator->getMethod("testFunc1", "void", MethodCSharp::PUBLIC));
	myClass->add(generator->getMethod("testFunc2", "void", MethodCSharp::PRIVATE | MethodCSharp::STATIC));
	myClass->add(generator->getMethod("testFunc3", "void", MethodCSharp::PUBLIC | MethodCSharp::VIRTUAL));
	auto method = generator->getMethod("testFunc4", "void", MethodCSharp::PROTECTED | MethodCSharp::INTERNAL | MethodCSharp::STATIC);
	method->add(generator->getPrintOperator(R"(Hello, world!\n)"));
	myClass->add(method);
	return myClass->compile();
}

std::string generateProgramDefault(const ICodeGenerator* generator) {
	auto myClass = generator->getClass("MyClass");
	myClass->add(generator->getMethod("testFunc1", "void"));
	myClass->add(generator->getMethod("testFunc2", "void"));
	myClass->add(generator->getMethod("testFunc3", "void"));
	auto method = generator->getMethod("testFunc4", "void");
	method->add(generator->getPrintOperator(R"(Hello, world!\n)"));
	myClass->add(method);
	return myClass->compile();
}

int main() {
	std::cout << generateProgramCPP() << std::endl;
	std::cout << std::endl;
	std::cout << generateProgramJava() << std::endl;
	std::cout << std::endl;
	std::cout << generateProgramCSharp() << std::endl;

	std::cout << std::endl << "=====================" << std::endl << std::endl;

	std::vector<std::shared_ptr<ICodeGenerator>> generators;
	generators.push_back(std::make_shared<CodeGeneratorCPP>());
	generators.push_back(std::make_shared<CodeGeneratorJava>());
	generators.push_back(std::make_shared<CodeGeneratorCSharp>());

	for (auto& generator : generators) {
		std::cout << generateProgramDefault(generator.get()) << std::endl << std::endl;
	}

	return 0;
}