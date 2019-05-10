#include <iostream>
#include "Map.h"

Map::Map() : Map::Map(0) { }

Map::Map(int s) {
	this->size = s;
}

void Map::set_size(int s) {
	this->size = s;
}

void Map::print() {
	std::cout << "Size is " << this->size << std::endl;
}

