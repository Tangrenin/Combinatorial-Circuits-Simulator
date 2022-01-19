//
// Created by user on 20/12/2021.
//

#include "AndGate.h"
#include <iostream>

using namespace std;

AndGate::AndGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void AndGate::afficher() const {
    cout << getText();
}

int AndGate::calculer() const {
    return g_left->calculer() and g_right->calculer();
}

void AndGate::showExpression() const {
    cout << "AND";
}

std::string AndGate::getText() const {
    return "and(" + g_left->getText() + "," + g_right->getText() + ")";
}

ostream &operator<<(ostream &out, const AndGate *g) {
    out << "AND";
    return out;
}