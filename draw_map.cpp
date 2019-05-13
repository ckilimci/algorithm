#include <iostream>
#include "Map.h"

int main() {
	std::cout << "Hello" << std::endl;
	Map m(5);
	m.print();
	m.zone[3][0] = 1;
	m.zone[3][1] = 1;
	m.draw();
	m.find_path(0,0, 4,0);
	return 0;
}
