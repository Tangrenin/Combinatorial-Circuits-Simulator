//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_UNARYGATE_H
#define UNTITLED7_UNARYGATE_H

#include "Gate.h"

class UnaryGate : public Gate {
protected:
    Gate* g_main;
public:
    UnaryGate(Gate* main);
    Gate* getGate();
};


#endif //UNTITLED7_UNARYGATE_H
