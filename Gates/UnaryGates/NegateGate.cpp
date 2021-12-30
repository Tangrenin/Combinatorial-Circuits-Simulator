//
// Created by user on 21/12/2021.
//

#include "NegateGate.h"
#include <iostream>

using namespace std;

NegateGate::NegateGate(Gate *main) : UnaryGate(main) {}

void NegateGate::afficher() {
    cout << "negate(";
    g_main->afficher();
    cout << ")";
}

int NegateGate::calculer() {
    return not g_main->calculer();
}

void NegateGate::showExpression() {
    cout << "NE";
}
