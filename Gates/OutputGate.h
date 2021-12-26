//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_OUTPUTGATE_H
#define UNTITLED7_OUTPUTGATE_H

#include "Gate.h"
#include <string>
#include <vector>

class OutputGate {
private:
    std::vector<std::vector<Gate*>> g_pile;
    Gate* g_main;
    std::string const g_main_text;
public:
    explicit OutputGate(Gate* main);
    OutputGate(std::string mainText);
    Gate* getMainGate();
    std::string getMainText();
    void textToGatePile();
    std::vector<std::vector<Gate*>> getPile();
    void afficher();
    int calculer();

};


#endif //UNTITLED7_OUTPUTGATE_H
