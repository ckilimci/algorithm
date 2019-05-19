#include <iostream>

int gcd(int x, int y) {
	int greater = std::max(x,y);
	int dividend = std::min(x,y);
	while (0 != greater%dividend) {
		std::cout << "g:" << greater << "d:" << dividend << std::endl;
		int new_dividend = greater % dividend;
		greater = dividend;
		dividend = new_dividend;
	}
	return dividend;
}

int lcm(int x, int y) {
	return (x*y)/gcd(x,y);
}

int nthmagicalnumber(int N, int A, int B) {
	int x=0, min_x=0, max_x=10000, fx=0, LCM=lcm(A,B);
	int i=0;
	while (min_x < max_x) {
		// calculate x
		//
		x = (min_x+max_x) / 2;
		std::cout << "Calculated x:" << x << std::endl;
		std::cout << "max:" << max_x << "min_x" << min_x << std::endl;

		fx = x/A + x/B - x/LCM;
		std::cout << "fx:" << fx << std::endl;

		if (fx < N) {
			min_x = x + 1;
		} else {
			max_x = x;
		}
		std::cout << "New max:" << max_x << "new min" << min_x << std::endl << std::endl;
	}
	return min_x;
}

int main() {
	std::cout << "A positive integer is magical if it is divisible by either A or B." << std::endl;
	std::cout << "Return the N-th magical number.  Since the answer may be very large, return it modulo 10^9 + 7" << std::endl;
	std::cout << "nthmagicalnumber(15, 2, 3):" << nthmagicalnumber(15, 2, 3) << std::endl;
	return 0;
}
