//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_UNARYGATE_H
#define UNTITLED7_UNARYGATE_H

#include "Gate.h"
#include <string>

class UnaryGate : public Gate {
protected:
    Gate* g_main;
public:
    explicit UnaryGate(Gate* main);
    int getProfondeur() const override;
    Gate* getGate() const;
    std::string getType() const override;

    std::vector<std::vector<Gate*>>  empileGates() override;
};


#endif //UNTITLED7_UNARYGATE_H
