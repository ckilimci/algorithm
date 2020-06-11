//
// Created by caglar on 11.06.2020.
//

#ifndef STATEMACHINE_MACHINE_H
#define STATEMACHINE_MACHINE_H

#include "State.h"

class Machine {
public:
    Machine();
    void enter();
    void payOK();
    void payFail();
    void changeState(State *);

private:
    State *state;
};


#endif //STATEMACHINE_MACHINE_H
