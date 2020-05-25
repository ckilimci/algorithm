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
