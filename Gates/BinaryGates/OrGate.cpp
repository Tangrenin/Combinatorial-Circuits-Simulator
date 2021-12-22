//
// Created by user on 20/12/2021.
//

#include "OrGate.h"
#include <iostream>
using namespace std;

OrGate::OrGate(Gate* left, Gate* right) : BinaryGate(left, right) {}

void OrGate::afficher() {
    cout <<"or(";
    g_left->afficher();
    cout<<",";
    g_right->afficher();
    cout <<")";
}

int OrGate::calculer() {
    return g_left->calculer() or g_right->calculer();
}