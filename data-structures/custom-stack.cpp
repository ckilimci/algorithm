#include <iostream>
#include <stack>

/*
Implement a stack that has the following methods:

push(val), which pushes an element onto the stack
pop(), which pops off and returns the topmost element of the stack. If there are no elements in the stack, then it should throw an error or return null.
max(), which returns the maximum value in the stack currently. If there are no elements in the stack, then it should throw an error or return null.
Each method should run in constant time.
*/

class CustomStack {
	int max_value;
	std::stack<int> local_stack;
	public:
	int pop() {
		if (local_stack.size() == 0) return INT_MIN;
		int popped = local_stack.top();
		local_stack.pop();
		if (popped > max_value) {
			max_value = 2*max_value - popped;
			return max_value;
		}	
		return popped;
	}
	void push (const int& val) {
		if (local_stack.size() == 0) {
			local_stack.push(val);
			max_value = val;
			return;
		}
		if ( max_value < val) {
			local_stack.push(2*val-max_value);
			max_value = val;
		} else {
			local_stack.push(val);
		}
	}
	int max() {
		return max_value;
	}
};

int main() {
	std::cout << "Hello Custom Stack" << std::endl;
	CustomStack s;
	s.push(10);
	s.push(20);
	s.push(15);
	s.push(5);
	s.push(30);
	std::cout << "Max :" << s.max() << std::endl;
	std::cout << "Pop :" << s.pop() << std::endl;
	std::cout << "Pop :" << s.pop() << std::endl;
	std::cout << "Max :" << s.max() << std::endl;
	return 0;
}
