//
// Created by caglar on 11.06.2020.
//

#include "CloseState.h"
#include "OpenState.h"
#include <iostream>

CloseState::CloseState(Machine * m) {
    this->machine = m;
}

void CloseState::enter() {
    std::cout << "@Close In the enter" << std::endl;
}

void CloseState::payOK() {
    std::cout << "@Close In the pay OK" << std::endl;
    this->machine->changeState(new OpenState(this->machine));
}

void CloseState::payFail() {
    std::cout << "@Close In the pay FAIL" << std::endl;
}