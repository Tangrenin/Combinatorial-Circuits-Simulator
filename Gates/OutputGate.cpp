//
// Created by user on 20/12/2021.
//

#include "OutputGate.h"
#include <iostream>

using namespace std;

void OutputGate::afficher() {
    g_main->afficher();
    cout<< endl;
}

int OutputGate::calculer() {
    return g_main->calculer();
}

OutputGate::OutputGate(Gate* main): g_main(main) {}

OutputGate::OutputGate(std::string mainText): g_main_text(mainText) {}

std::string OutputGate::getMainText() {
    return g_main_text;
}

Gate *OutputGate::getMainGate() {
    return g_main;
}

