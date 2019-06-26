#include <iostream>
#include <vector>

template <class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v) {
	os << "[";
	for(auto e : v) {
		os << " " << e;
	}
	os << " ]";
	return os;
}

int partition(std::vector<int>& array, const int low, const int high) {
	int pivot = high;
	int i = low - 1;
	for (int j=low; j<high; j++) {
		if (array[j] >= array[pivot]) {
			i++;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i+1], array[pivot]);
	return i+1;
}

int findKthLargest(std::vector<int>& nums, int k, int low, int high) {
	if (k > high) return INT_MAX;
	if (low<high) {
		int pi = partition(nums, low, high);
		std::cout << nums << std::endl;
		
		if (pi == k) {
			return nums[pi];
		} else if (pi > k) {
			return findKthLargest(nums, k, low, pi-1);
		} else {
			return findKthLargest(nums, k, pi+1, high);
		}
	}
	return INT_MIN;
}

int findKthLargest(std::vector<int>& nums, int k) {
	return findKthLargest(nums, k, 0, nums.size()-1);
} 

int main() {
	std::cout << "Kth Largest Element in the Array" << std::endl;
	std::vector<int> array { 5, 23, 67, 23, 80, 99, 13, 18 };

	std::cout << array << std::endl;
	
	int K = 6;
	std::cout << "Largest " << K << "th element is " << findKthLargest(array, K) << std::endl;
	
	return 0;
}
