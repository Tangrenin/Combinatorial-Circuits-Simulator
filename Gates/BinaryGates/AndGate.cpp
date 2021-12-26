//
// Created by user on 20/12/2021.
//

#include "AndGate.h"
#include <iostream>
using namespace std;

AndGate::AndGate(Gate* left, Gate* right) : BinaryGate(left, right) {}

void AndGate::afficher() {
    cout <<"and(";
    g_left->afficher();
    cout<<",";
    g_right->afficher();
    cout <<")";
}

int AndGate::calculer() {
    return g_left->calculer() and g_right->calculer();
}

void AndGate::showExpression() {
    cout<<"AND";
}

ostream& operator<<(ostream& out, const AndGate * g){
    out << "AND";
    return out;
}