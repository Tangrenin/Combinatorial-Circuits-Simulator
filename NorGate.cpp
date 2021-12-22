//
// Created by user on 21/12/2021.
//

#include "NorGate.h"

#include <iostream>
using namespace std;

NorGate::NorGate(Gate* left, Gate* right) : BinaryGate(left, right) {}

void NorGate::afficher() {
    cout <<"nor(";
    g_left->afficher();
    cout<<",";
    g_right->afficher();
    cout <<")";
}

int NorGate::calculer() {
    return not(g_left->calculer()) or not(g_right->calculer());
}