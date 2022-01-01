//
// Created by user on 21/12/2021.
//

#include "NandGate.h"

#include <iostream>

using namespace std;

NandGate::NandGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void NandGate::afficher() const {
    cout << "nand(";
    g_left->afficher();
    cout << ",";
    g_right->afficher();
    cout << ")";
}

int NandGate::calculer() const {
    return not((g_left->calculer()) and (g_right->calculer()));
}

void NandGate::showExpression() const {
    cout << "NAND";
}

ostream &operator<<(ostream &out, const NandGate *g) {
    out << "NAND";
    return out;
}