//
// Created by user on 20/12/2021.
//

#include "InputGate.h"
#include <iostream>

using namespace std;
InputGate::InputGate(char inputG): input(inputG) {}

char InputGate::getInput() const {
    return input;
}

int InputGate::getValue() const {
    return value;
}

void InputGate::afficher() {
    cout <<input;

}

int InputGate::calculer() {
    return this->getValue();
}

int InputGate::getProfondeur() const {
    return profondeur;
}

std::string InputGate::getType() const {
    return "input";
}

void InputGate::showExpression() {
    cout << this->getInput();
}

std::vector<std::vector<Gate *>> InputGate::empileGates() {
    vector<vector<Gate*>> g_pile;
    vector<Gate*> sous_pile;
    sous_pile.push_back(this);
    g_pile.push_back(sous_pile);
    return g_pile;
}

ostream& operator<<(ostream& out, const InputGate * g){
    out << g->getInput();
    return out;
}
