#include "MethodCPP.h"
#include "ClassCPP.h"
#include "PrintOperatorCPP.h"
#include <iostream>
#include "ClassJava.h"

std::string generateProgram() {
	ClassCPP myClass("MyClass");
	myClass.add(std::make_shared<MethodCPP>("testFunc1", "void", 0), ClassCPP::PUBLIC);
	myClass.add(std::make_shared<MethodCPP>("testFunc2", "void", MethodCPP::STATIC), ClassCPP::PRIVATE);
	myClass.add(std::make_shared<MethodCPP>("testFunc3", "void", MethodCPP::VIRTUAL | MethodCPP::CONST), ClassCPP::PUBLIC);
	auto method = std::make_shared<MethodCPP>("testFunc4", "void", MethodCPP::STATIC);
	method->add(std::make_shared<PrintOperatorCPP>(R"(Hello, world!\n)"));
	myClass.add(method, ClassCPP::PROTECTED);
	return myClass.compile();
}

int main() {
	std::cout << generateProgram() << std::endl;
	return 0;
}