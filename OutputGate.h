//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_OUTPUTGATE_H
#define UNTITLED7_OUTPUTGATE_H

#include "Gate.h"

class OutputGate {
private:
    Gate* g_main;
public:
    OutputGate(Gate* main);
    void afficher();
    int calculer();
};


#endif //UNTITLED7_OUTPUTGATE_H
