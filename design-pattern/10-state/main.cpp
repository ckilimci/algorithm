#include <iostream>

#include "Machine.h"
#include "OpenState.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    Machine m;
    m.enter();
    m.payFail();
    m.payOK();
    m.payOK();
    m.payOK();
    m.payOK();
    m.enter();
    m.enter();
    return 0;
}
