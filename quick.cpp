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
		if (array[j] <= array[pivot]) {
			i++;
			std::swap(array[i], array[j]);
		}
	}
	std::swap(array[i+1], array[pivot]);
	return i+1;
}

void quick_sort(std::vector<int>& array, const int low, const int high) {
	if (low < high) {
		int pi = partition(array, low, high);
		std::cout << array << std::endl;

		quick_sort(array, low, pi-1);
		quick_sort(array, pi+1, high);
	}
}

void quick_sort(std::vector<int>& array) {
	std::cout << "Entered Quick Sort" << std::endl;
	quick_sort(array, 0, array.size()-1);
}


int main() {
	std::cout << "Quick Sort" << std::endl;
	std::vector<int> array { 5, 23, 67, 23, 80, 99, 13, 18 };

	std::cout << array << std::endl;
	
	quick_sort(array);

	std::cout << array << std::endl;
	
	return 0;
}
