#include <iostream>
#include "Duck.h"

int main() {
	std::cout << "Hello" << std::endl;
	Duck d("cirkin");
	d.quack();
	d.swim();
	return 0;
}
