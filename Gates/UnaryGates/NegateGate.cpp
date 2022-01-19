//
// Created by user on 21/12/2021.
//

#include "NegateGate.h"
#include <iostream>

using namespace std;

NegateGate::NegateGate(Gate *main) : UnaryGate(main) {}

void NegateGate::afficher() const {
    cout << getText();
}

int NegateGate::calculer() const {
    return not g_main->calculer();
}

void NegateGate::showExpression() const {
    cout << "NE_";
}

std::string NegateGate::getText() const {
    return "negate(" + g_main->getText() + ")";
}
