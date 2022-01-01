//
// Created by user on 20/12/2021.
//

#include "OrGate.h"
#include <iostream>

using namespace std;

OrGate::OrGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void OrGate::afficher() const {
    cout << "or(";
    g_left->afficher();
    cout << ",";
    g_right->afficher();
    cout << ")";
}

int OrGate::calculer() const {
    return g_left->calculer() or g_right->calculer();
}

void OrGate::showExpression() const {
    cout << "OR_";
}

ostream &operator<<(ostream &out, const OrGate *g) {
    out << "OR";
    return out;
}