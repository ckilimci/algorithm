//
// Created by caglar on 11.06.2020.
//

#ifndef STATEMACHINE_STATE_H
#define STATEMACHINE_STATE_H

class State {
public:
    virtual void enter() = 0;
    virtual void payFail() = 0;
    virtual void payOK() = 0;
};

#endif //STATEMACHINE_STATE_H
