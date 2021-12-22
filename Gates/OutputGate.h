//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_OUTPUTGATE_H
#define UNTITLED7_OUTPUTGATE_H

#include "Gate.h"
#include <string>

class OutputGate {
private:
    Gate* g_main;
    std::string const g_main_text;
public:
    OutputGate(Gate* main);
    OutputGate(std::string mainText);
    Gate* getMainGate();
    std::string getMainText();
    void afficher();
    int calculer();
};


#endif //UNTITLED7_OUTPUTGATE_H
