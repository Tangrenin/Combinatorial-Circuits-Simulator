//
// Created by user on 20/12/2021.
//

#include "XorGate.h"
#include <iostream>

using namespace std;

XorGate::XorGate(Gate *left, Gate *right) : BinaryGate(left, right) {}


void XorGate::afficher() const {
    cout << getText();
}

int XorGate::calculer() const {
    return g_left->calculer() xor g_right->calculer();
}

void XorGate::showExpression() const {
    cout << "XOR";
}

std::string XorGate::getText() const {
    return "xor(" + g_left->getText() + "," + g_right->getText() + ")";
}

ostream &operator<<(ostream &out, const XorGate *g) {
    out << "XOR";
    return out;
}