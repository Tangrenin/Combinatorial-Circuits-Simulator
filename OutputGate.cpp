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

