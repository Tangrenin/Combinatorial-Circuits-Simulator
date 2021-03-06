//
// Created by user on 14/01/2022.
//

#include "NxorGate.h"

#include <iostream>

using namespace std;

NxorGate::NxorGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void NxorGate::afficher() const {
    cout << getText();;
}

int NxorGate::calculer() const {
    return not((g_left->calculer()) or (g_right->calculer()));
}

void NxorGate::showExpression() const {
    cout << "NXOR";
}

std::string NxorGate::getText() const {
    return "nxor(" + g_left->getText() + "," + g_right->getText() + ")";
}

ostream &operator<<(ostream &out, const NxorGate *g) {
    out << "NXOR";
    return out;
}