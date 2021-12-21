//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_ANDGATE_H
#define UNTITLED7_ANDGATE_H

#include "BinaryGate.h"

class AndGate : public BinaryGate{
private:
public:
    AndGate(Gate* left, Gate* right);
    void afficher() override;
    int calculer() override;
};


#endif //UNTITLED7_ANDGATE_H
