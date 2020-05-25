#include <iostream>
#include "Duck.h"

class MallardDuck : public Duck {
public:
    MallardDuck(std::string name) : Duck(name) {}

    void display() {
        std::cout << this->name << " is a mallard duck" << std::endl;
    };
};
