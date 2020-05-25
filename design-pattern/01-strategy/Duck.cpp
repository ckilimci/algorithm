#include <iostream>
#include "Duck.h"

Duck::Duck(std::string name) {
	std::cout << "Duck " << name << " is borning" << std::endl;
	this->name = name;
}

void Duck::quack() {
	std::cout << this->name << " says \"quack quack\"" << std::endl;
}

void Duck::swim() {
	std::cout << this->name << " is swimming" << std::endl;
}

void Duck::fly() {
    std::cout << this->name << " is flying.." << std::endl;
}

void Duck::display() {
    std::cout << this->name << " is a duck" << std::endl;
}
