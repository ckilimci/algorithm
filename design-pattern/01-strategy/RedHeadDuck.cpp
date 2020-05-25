#include <iostream>
#include "Duck.h"

class RedHeadDuck : public Duck {
public:
    RedHeadDuck(std::string name) : Duck(name) {}

    void display() {
        std::cout << this->name << " is a red head duck" << std::endl;
    };
};
