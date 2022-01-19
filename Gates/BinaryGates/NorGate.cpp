//
// Created by user on 21/12/2021.
//

#include "NorGate.h"

#include <iostream>

using namespace std;

NorGate::NorGate(Gate *left, Gate *right) : BinaryGate(left, right) {}

void NorGate::afficher() const {
    cout << "nor(";
    g_left->afficher();
    cout << ",";
    g_right->afficher();
    cout << ")";
}

int NorGate::calculer() const {
    return not((g_left->calculer()) or (g_right->calculer()));
}

void NorGate::showExpression() const {
    cout << "NOR";
}

std::string NorGate::getText() const {
    return "nor("+g_left->getText()+","+g_right->getText()+")";
}

ostream &operator<<(ostream &out, const NorGate *g) {
    out << "NOR";
    return out;
}