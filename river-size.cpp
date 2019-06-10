#include <iostream>
#include <vector>

/*
You are given a two-dimensional array (matrix) of potentially unequal height and width containing only 0s and 1s. Each 0 represents land, and each 1 represents part of a river. A river consists of any number of 1s that are either horizontally or vertically adjacent (but not diagonally adjacent). The number of adjacent 1s forming a river determine its size. Write a function that returns an array of the sizes of all rivers represented in the input matrix. Note that these sizes do not need to be in any particular order.
*/

int searchMatrix(std::vector<std::vector<int> > & matrix, int r, int c) {
	//std::cout << "r=" << r << " c=" << c << " matrix[r][c]=" << matrix[r][c] << std::endl;
	if (matrix[r][c] == 0) return 0;
	matrix[r][c] = 0;
	int size = 1;
	if (r<matrix.size()-1)
		size += searchMatrix(matrix, r+1, c);
	if (r>0)
		size += searchMatrix(matrix, r-1, c);
	if (c<matrix[0].size()-1)
		size += searchMatrix(matrix, r, c+1);
	if (c>0)
		size += searchMatrix(matrix, r, c-1);
	return size;
}

std::vector<int> riverSizes(std::vector<std::vector<int> > matrix) {
	std::vector<int> result;
	int ROW = matrix.size();
	int COL = matrix[0].size();
	for(int r=0; r<ROW; r++) {
		for(int c=0; c<COL; c++) {
			std::cout << matrix[r][c] << " ";
		}
		std::cout << std::endl;
	}
	for(int r=0; r<ROW; r++) {
		for(int c=0; c<COL; c++) {
			if (matrix[r][c] != 0) {
				//std::cout << "----------------" << std::endl << std::endl;
				result.push_back(searchMatrix(matrix, r, c));
			}
		}
	}	
	return result;
}

int main() {
	std::cout << "Hello River Size" << std::endl;
	std::vector<std::vector<int> > testInput {
	//	 0  1  2  3  4  5  6  7  8  9 10 11
		{1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0},
		{1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0},
		{0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1},
		{1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0},
		{1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1},
	};
	std::vector<int> results = riverSizes(testInput);
	int i=1;
	for(auto result : results) {
		std::cout << i++ << "=>" << result << std::endl;
	}
	return 0;
}
