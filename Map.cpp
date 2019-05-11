#include <iostream>
#include <vector>
#include "Map.h"

Map::Map() : Map::Map(4) { }

Map::Map(int s) {
	this->row = s;
	this->col = s;
	this->zone = std::vector<std::vector<int>>(s, std::vector<int>(s));
}

Map::Map(int r, int c) {
	this->row = r;
	this->col = c;
	this->zone = std::vector<std::vector<int>>(r, std::vector<int>(c));
}

void Map::set_size(int s) {
	this->row = s;
	this->col = s;
}

void Map::print() {
	std::cout << "Row is " << this->row << std::endl;
	std::cout << "Column is " << this->col << std::endl;
}

void Map::draw() {
	for(int i=0; i<this->row; i++) {
		for(int j=0; j<this->col; j++) {
			std::cout << this->zone[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

