//
// Created by caglar on 11.06.2020.
//

#include "Machine.h"
#include "OpenState.h"
#include "CloseState.h"
#include <iostream>

Machine::Machine() {
    this->state = new CloseState(this);
}

void Machine::changeState(State * newState) {
    if (this->state != newState) {
        delete this->state;
        this->state = newState;
    }
}

void Machine::enter() {
    this->state->enter();
}

void Machine::payOK() {
    this->state->payOK();
}

void Machine::payFail() {
    this->state->payFail();
}