#include <iostream>

class MyClass {
	int data;
	public:
	MyClass(int d) { data = d; }
	void print() { std::cout << "Data: " << data << std::endl; }
	~MyClass() { }
};

int main() {
	std::cout << "Hello Smart Pointers" << std::endl;
	MyClass *ptr(new MyClass(5));
	MyClass *ptr2;
	ptr2 = ptr;
	delete ptr;
	ptr->print(); // This will work until we assign ptr as a NULL
	ptr = nullptr;
	ptr->print(); // Now, this will not work!
	return 0;
}
