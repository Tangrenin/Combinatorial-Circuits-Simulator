//
// Created by user on 20/12/2021.
//

#include "XorGate.h"
#include <iostream>

using namespace std;

XorGate::XorGate(Gate *left, Gate *right) : BinaryGate(left, right) {}


void XorGate::afficher() const {
    cout << "xor(";
    g_left->afficher();
    cout << ",";
    g_right->afficher();
    cout << ")";
}

int XorGate::calculer() const {
    return g_left->calculer() xor g_right->calculer();
}

void XorGate::showExpression() const {
    cout << "XOR";
}

ostream &operator<<(ostream &out, const XorGate *g) {
    out << "XOR";
    return out;
}