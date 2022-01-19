//
// Created by user on 21/12/2021.
//

#include "NandGate.h"

#include <iostream>

using namespace std;

NandGate::NandGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void NandGate::afficher() const {
    cout << getText();;
}

int NandGate::calculer() const {
    return not((g_left->calculer()) and (g_right->calculer()));
}

void NandGate::showExpression() const {
    cout << "NAN";
}

std::string NandGate::getText() const {
    return "nand(" + g_left->getText() + "," + g_right->getText() + ")";
}

ostream &operator<<(ostream &out, const NandGate *g) {
    out << "NAND";
    return out;
}