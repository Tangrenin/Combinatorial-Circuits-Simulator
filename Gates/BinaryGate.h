//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_BINARYGATE_H
#define UNTITLED7_BINARYGATE_H

#include "Gate.h"
#include <string>

class BinaryGate : public Gate{
protected:
    Gate* g_left;
    Gate* g_right;

public:
    BinaryGate(Gate* left, Gate* right);

    Gate* getGateRight() const ;
    Gate* getGateLeft() const ;
    int getProfondeur() const override;
    std::string getType() const override;

    std::vector<std::vector<Gate*>>  empileGates() override;
};


#endif //UNTITLED7_BINARYGATE_H
