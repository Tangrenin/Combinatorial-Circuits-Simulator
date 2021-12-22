//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_BINARYGATE_H
#define UNTITLED7_BINARYGATE_H

#include "Gate.h"

class BinaryGate : public Gate{
protected:
    Gate* g_left;
    Gate* g_right;

public:
    BinaryGate(Gate* left, Gate* right);
    //virtual int calculer()=0;
    Gate* getGateRight() const;
    Gate* getGateLeft() const;
    //void afficher() override =0;
};


#endif //UNTITLED7_BINARYGATE_H
