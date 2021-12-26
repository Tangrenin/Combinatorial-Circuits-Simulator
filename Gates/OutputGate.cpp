//
// Created by user on 20/12/2021.
//

#include "OutputGate.h"
#include <iostream>
#include <queue>
using namespace std;

void OutputGate::afficher() {
    g_main->afficher();
    cout<< endl;
}

int OutputGate::calculer() {
    return g_main->calculer();
}

OutputGate::OutputGate(Gate* main): g_main(main), g_pile(vector<vector<Gate*>>()) {
    g_pile = g_main->empileGates();
}

OutputGate::OutputGate(std::string mainText): g_main(nullptr), g_main_text(mainText) {}

std::string OutputGate::getMainText() {
    return g_main_text;
}

Gate *OutputGate::getMainGate() {
    return g_main;
}



std::vector<std::vector<Gate *>> OutputGate::getPile() {
    return g_pile;
}

void OutputGate::textToGatePile() {
    /**
    string inputCopy = g_main_text;
    vector<string> gates_text;
    int pos;
    while ((pos=inputCopy.find("("))!=0){
        gates_text.push_back(inputCopy.substr(0,pos));
    }
     **/

}

