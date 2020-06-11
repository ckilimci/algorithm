//
// Created by caglar on 11.06.2020.
//

#ifndef STATEMACHINE_CLOSESTATE_H
#define STATEMACHINE_CLOSESTATE_H


#include "State.h"
#include "Machine.h"

class CloseState : public State {
public:
    CloseState(Machine *);
    void enter();
    void payOK();
    void payFail();

private:
    Machine *machine;
};

#endif //STATEMACHINE_CLOSESTATE_H
