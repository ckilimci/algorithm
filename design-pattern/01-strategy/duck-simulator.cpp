#include <iostream>
#include "Duck.h"
#include "MallardDuck.cpp"
#include "RedHeadDuck.cpp"

int main() {
    std::cout << "Hello" << std::endl;
    RedHeadDuck d("cirkin");
    d.quack();
    d.swim();
    d.display();


    return 0;
}
