//
// Created by user on 20/12/2021.
//

#include "InputGate.h"
#include <iostream>

using namespace std;

InputGate::InputGate(char inputG, bool value) : input(inputG), value(value) {}


char InputGate::getInput() const {
    return input;
}

int InputGate::getValue() const {
    return value;
}

void InputGate::setValue(bool newValue) {
    value = newValue;
}


void InputGate::afficher() {
    cout << input;

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
    cout << this->getInput() << ":" << this->getValue();
}

std::vector<std::vector<Gate *>> InputGate::empileGates() {
    vector<vector<Gate *>> g_pile;
    vector<Gate *> sous_pile;
    sous_pile.push_back(this);
    g_pile.push_back(sous_pile);
    return g_pile;
}

void InputGate::showLigne() {
    cout << " | ";
}

ostream &operator<<(ostream &out, const InputGate *g) {
    out << g->getInput();
    return out;
}
