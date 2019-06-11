#include <iostream>
#include <vector>
#include <unordered_map>

/*
Write a function that takes in an array of integers and returns an array of length 2 representing the largest range of numbers contained in that array. The first number in the output array should be the first number in the range while the second number should be the last number in the range. A range of numbers is defined as a set of numbers that come right after each other in the set of real integers. For instance, the output array [2, 6] represents the range {2, 3, 4, 5, 6}, which is a range of length 5. Note that numbers do not need to be ordered or adjacent in the array in order to form a range. Assume that there will only be one largest range.
Sample input: [1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6]
Sample output: [0, 7]
*/

void print(std::vector<int> array) {
	for(auto element : array) {
		std::cout << element << " ";
	}
	std::cout << std::endl;
}

std::vector<int> largestRange(std::vector<int> array) {
	std::vector<int> result;
	std::unordered_map<int, bool> dict;
	for (auto element : array) {
		dict[element] = false;
	}
	int index=0;
	int min_range = array[index];
	int max_range = array[index];
	while(index<array.size()) {
		int current = array[index];
		// std::cout << "Current: " << current << std::endl;
		int local_min = current;
		int local_max = current;
		if (!dict[current]) {
			// std::cout << "Current is not visited yet! " << dict[current] << std::endl;
			dict[current] = true;
			// Look for the before
			while(dict.end() != dict.find(--current)) {
				// std::cout << "Searching for the before. Current: " << current << std::endl;
				dict[current] = true;
				local_min = current;
			}
			current = array[index];
			// Look for the after
			while(dict.end() != dict.find(++current)) {
				// std::cout << "Searching for the after. Current: " << current << std::endl;
				dict[current] = true;
				local_max = current;
			}
			if ((max_range-min_range)<(local_max-local_min)) {
				// std::cout << "New range found! Max: " << local_max << " Min: " << local_min << std::endl;
				max_range = local_max;
				min_range = local_min;
			}
		}
		index++;
	}
	result.push_back(min_range);
	result.push_back(max_range);
	return result;
}

int main() {
	std::cout << "Hello Largest Range" << std::endl;

	std::vector<int> array { 1, 11, 3, 0, 15, 5, 2, 4, 10, 7, 12, 6 };
	std::cout << "Array is:" << std::endl;
	print(array);
	std::cout << "Largest is:" << std::endl;
	print(largestRange(array));
	return 0;
}







