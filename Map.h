#include <iostream>
#include <vector>

class Map {
	public:
	int row;
	int col;
	std::vector<std::vector<int> > zone;
	Map();
	Map(int);
	Map(int, int);
	void set_size(int);
	void print();
	void draw();
	void find_path(int, int, int, int);
};
