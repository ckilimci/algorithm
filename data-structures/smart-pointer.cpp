#include <iostream>
#include <memory>

class MyClass {
	int data;
	public:
	MyClass(int d) { data = d; }
	void print() { std::cout << "Data: " << data << std::endl; }
	~MyClass() { }
};

int main() {
	std::cout << "Hello Smart Pointers" << std::endl;
	std::shared_ptr<MyClass> ptr(new MyClass(5));
	ptr->print();
	std::shared_ptr<MyClass> ptr2;
	ptr2 = ptr;      // This is valid.
	ptr2->print();   // This will work;
	ptr.reset();     // Memory still exists, due to ptr2
	// ptr->print(); // But this will not work!
	ptr2->print();   // This will work.

	std::unique_ptr<MyClass> p1(new MyClass(3));
	p1->print();
	std::unique_ptr<MyClass> p2;
	// p2 = p1;      // This is not valid!
	p2 = std::move(p1);
	p2->print(); 
	p1.reset();      // This does nothing!
	p2->print(); 
	p2.reset();      // This deletes the memory;
	// p2->print();  // This is a problem!
	return 0;
}
