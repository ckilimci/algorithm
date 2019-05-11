#include <iostream>
#include "Map.h"

int main() {
	std::cout << "Hello" << std::endl;
	Map m(3);
	m.print();
	m.zone[1][0] = 1;
	m.zone[1][1] = 1;
	m.draw();
	return 0;
}
