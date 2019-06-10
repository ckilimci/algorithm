#include <iostream>
#include <vector>

/*
Given a list of integers S and a target number k, write a function that returns a subset of S that adds up to k. If such a subset cannot be made, then return null.

Integers can appear more than once in the list. You may assume all numbers in the list are positive.

For example, given S = [12, 1, 61, 5, 9, 2] and k = 24, return [12, 9, 2, 1] since it sums up to 24.
*/

std::vector<int> subsetSum(std::vector<int> set, int target, int index) {
	std::vector<int> result;
	if (target <= 0 || index>=set.size()) return result;
	if (target < set[index]) return subsetSum(set, target, index+1);
	if (target == set[index]) {
		result.push_back(set[index]);
		return result;
	}
	result = subsetSum(set, target-set[index], index+1);
	if (result.size() > 0) {
		result.push_back(set[index]);
	} else {
		result = subsetSum(set, target, index+1);
	}
	return result;
}

std::vector<int> subsetSum(std::vector<int> set, int target) {
	return subsetSum(set, target, 0);
}

int main() {
	std::cout << "Hello Subset Sum" << std::endl;
	std::vector<int> testSet { 12, 1, 61, 5, 9, 2 };
	std::cout << "Test Set is:";
	for (auto data : testSet) {
		std::cout << data << " ";
	}
	std::cout << std::endl;
	std::vector<int> results = subsetSum(testSet, 24);
	std::cout << "Result is:";
	for (auto result : results) {
		std::cout << result << " ";
	}
	std::cout << std::endl;
	return 0;
}
