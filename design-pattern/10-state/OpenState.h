//
// Created by caglar on 11.06.2020.
//

#ifndef STATEMACHINE_OPENSTATE_H
#define STATEMACHINE_OPENSTATE_H

#include "State.h"
#include "Machine.h"

class OpenState : public State {
public:
    OpenState(Machine*);
    void enter();
    void payOK();
    void payFail();

private:
    Machine* machine;
};


#endif //STATEMACHINE_OPENSTATE_H
