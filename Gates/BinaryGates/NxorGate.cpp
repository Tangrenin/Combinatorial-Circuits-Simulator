//
// Created by user on 14/01/2022.
//

#include "NxorGate.h"

#include <iostream>

using namespace std;

NxorGate::NxorGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void NxorGate::afficher() const {
    cout << "nxor(";
    g_left->afficher();
    cout << ",";
    g_right->afficher();
    cout << ")";
}

int NxorGate::calculer() const {
    return not((g_left->calculer()) or (g_right->calculer()));
}

void NxorGate::showExpression() const {
    cout << "NXR";
}

ostream &operator<<(ostream &out, const NxorGate *g) {
    out << "NXR";
    return out;
}