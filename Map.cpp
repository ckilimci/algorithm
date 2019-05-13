#include <iostream>
#include <vector>
#include <cmath>
#include <cstdint>
#include <limits.h>
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
	std::cout << "---" << std::endl;
	std::cin.get();
}

void Map::find_path(int startx, int starty, int endx, int endy) {
	std::cout << "Start point=(" << startx << "," << starty << ")" << std::endl;
	int x = startx;
	int y = starty;
	int gx = 0;
	int hx = 0;
	Map costs(this->row, this->col);
	Map visited(this->row, this->col);
	while(x != endx || y != endy) {
		std::cout << "We are now at (" << x << "," << y << ")"  << std::endl;
		visited.zone[x][y] = 1;
		gx = pow(startx-x, 2)+pow(starty-y, 2);
		hx = pow(endx-x, 2)+pow(endy-y, 2);
		costs.zone[y][y] = gx + hx;
		int min = INT_MAX;
		int minx, miny;
		// top left
		if ((x-1)>=0 && (y-1)>=0) {
			if (this->zone[x-1][y-1] == 0) {
				// std::cout << "We can go top left" << std::endl;
				gx = pow(startx-(x-1), 2)+pow(starty-(y-1), 2);
				hx = pow(endx-(x-1), 2)+pow(endy-(y-1), 2);
				costs.zone[x-1][y-1] = gx + hx;
				if (costs.zone[x-1][y-1] < min && visited.zone[x-1][y-1] == 0) {
					min = costs.zone[x-1][y-1];
					minx = x-1;
					miny = y-1;
				}
			}
		}
		
		// left
		if ((y-1)>=0) {
			if (this->zone[x][y-1] == 0) {
				// std::cout << "We can go left" << std::endl;
				gx = pow(startx-(x), 2)+pow(starty-(y-1), 2);
				hx = pow(endx-(x), 2)+pow(endy-(y-1), 2);
				costs.zone[x][y] = gx + hx;
				if (costs.zone[x][y-1] < min && visited.zone[x][y-1] == 0) {
					min = costs.zone[x][y-1];
					minx = x;
					miny = y-1;
				}
			}
		}

		// bottom left
		if ((x+1)<this->col && (y-1)>=0) {
			if (this->zone[x+1][y-1] == 0) {
				// std::cout << "We can go bottom left" << std::endl;
				gx = pow(startx-(x+1), 2)+pow(starty-(y-1), 2);
				hx = pow(endx-(x+1), 2)+pow(endy-(y-1), 2);
				costs.zone[x+1][y-1] = gx + hx;
				if (costs.zone[x+1][y-1] < min && visited.zone[x+1][y-1] == 0) {
					min = costs.zone[x+1][y-1];
					minx = x+1;
					miny = y-1;
				}
			}
		}
		// bottom
		if ((x+1)<this->col) {
			if (this->zone[x+1][y] == 0) {
				// std::cout << "We can go bottom" << std::endl;
				gx = pow(startx-(x+1), 2)+pow(starty-(y), 2);
				hx = pow(endx-(x+1), 2)+pow(endy-(y), 2);
				costs.zone[x+1][y] = gx + hx;
				if (costs.zone[x+1][y] < min && visited.zone[x+1][y] == 0) {
					min = costs.zone[x+1][y];
					minx = x+1;
					miny = y;
				}
			}
		}
		// bottom right
		if ((x+1)<this->col && (y+1)<this->row) {
			if (this->zone[x+1][y+1] == 0) {
				// std::cout << "We can go bottom right" << std::endl;
				gx = pow(startx-(x+1), 2)+pow(starty-(y+1), 2);
				hx = pow(endx-(x+1), 2)+pow(endy-(y+1), 2);
				costs.zone[x+1][y+1] = gx + hx;
				if (costs.zone[x+1][y+1] < min && visited.zone[x+1][y+1] == 0) {
					min = costs.zone[x+1][y+1];
					minx = x+1;
					miny = y+1;
				}
			}
		}
		// right
		if ((y+1)<this->row) {
			if (this->zone[x][y+1] == 0) {
				// std::cout << "We can go right" << std::endl;
				gx = pow(startx-(x), 2)+pow(starty-(y+1), 2);
				hx = pow(endx-(x), 2)+pow(endy-(y+1), 2);
				costs.zone[x][y+1] = gx + hx;
				if (costs.zone[x][y+1] < min && visited.zone[x][y+1] == 0) {
					min = costs.zone[x][y+1];
					minx = x;
					miny = y+1;
				}
			}
		}
		// top right
		if ((x-1)>=0 && (y+1)<this->row) {
			if (this->zone[x-1][y+1] == 0) {
				// std::cout << "We can go top right" << x-1 << "-" << y+1 << std::endl;
				gx = pow(startx-(x-1), 2)+pow(starty-(y+1), 2);
				hx = pow(endx-(x-1), 2)+pow(endy-(y+1), 2);
				costs.zone[x-1][y+1] = gx + hx;
				if (costs.zone[x-1][y+1] < min && visited.zone[x-1][y+1] == 0) {
					min = costs.zone[x-1][y+1];
					minx = x-1;
					miny = y+1;
				}
			}
		}
		// top
		if ((x-1)>=0) {
			if (this->zone[x-1][y] == 0) {
				// std::cout << "We can go top" << std::endl;
				gx = pow(startx-(x-1), 2)+pow(starty-(y), 2);
				hx = pow(endx-(x-1), 2)+pow(endy-(y), 2);
				costs.zone[x-1][y] = gx + hx;
				if (costs.zone[x-1][y] < min && visited.zone[x-1][y] == 0) {
					min = costs.zone[x-1][y];
					minx = x-1;
					miny = y;
				}
			}
		}
		visited.zone[x][y] = 1;
		x=minx;
		y=miny;
		//std::cout << "Minimum point is at (" << x << "," << y << ")"  << std::endl;
		//costs.draw();
	}
	std::cout << "End point=(" << endx << "," << endy << ")" << std::endl;
}
