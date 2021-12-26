//
// Created by user on 21/12/2021.
//

#include "NandGate.h"

#include <iostream>
using namespace std;

NandGate::NandGate(Gate* left, Gate* right) : BinaryGate(left, right) {}

void NandGate::afficher() {
    cout <<"nand(";
    g_left->afficher();
    cout<<",";
    g_right->afficher();
    cout <<")";
}

int NandGate::calculer() {
    return not(g_left->calculer()) and not(g_right->calculer());
}

void NandGate::showExpression() {
    cout<<"NAND";
}

ostream& operator<<(ostream& out, const NandGate * g){
    out << "NAND";
    return out;
}