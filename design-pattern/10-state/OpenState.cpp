//
// Created by caglar on 11.06.2020.
//

#include "OpenState.h"
#include "CloseState.h"
#include <iostream>

OpenState::OpenState(Machine * m) {
    this->machine = m;
}

void OpenState::enter() {
    std::cout << "@Open In the enter" << std::endl;
    this->machine->changeState(new CloseState(this->machine));
}

void OpenState::payOK() {
    std::cout << "@Open In the pay OK" << std::endl;
}

void OpenState::payFail() {
    std::cout << "@Open In the pay FAIL" << std::endl;
}