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

int main() {
	std::cout << "Hello" << std::endl;
	std::cout << "gcd(105,20):" << gcd(105,20) << std::endl;
	std::cout << "gcd(20,105):" << gcd(20,105) << std::endl;
	std::cout << "lcm(105,20):" << lcm(105,20) << std::endl;
	std::cout << "lcm(20,105):" << lcm(20,105) << std::endl;
	return 0;
}
