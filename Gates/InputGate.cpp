//
// Created by user on 20/12/2021.
//

#include "InputGate.h"
#include <iostream>

using namespace std;

InputGate::InputGate(char varName, bool value) : name(varName), value(value) {}

InputGate::~InputGate() = default;


// Getters
char InputGate::getName() const {
    return name;
}

int InputGate::getValue() const {
    return value;
}

//permet de modifier la valeur d'une expression à tout moment
void InputGate::setValue(bool newValue) {
    value = newValue;
}


void InputGate::afficher() const {
    cout << name;

}

int InputGate::calculer() const{
    return this->getValue();
}

int InputGate::getProfondeur() const {
    return profondeur;
}

string InputGate::getType() const {
    return "input";
}

void InputGate::showExpression() const {
    cout << this->getName() << ":" << this->getValue();
}

std::vector<std::vector<Gate *>> InputGate::empileGates() {
    vector<vector<Gate *>> g_pile;
    vector<Gate *> sous_pile;
    sous_pile.push_back(this);
    g_pile.push_back(sous_pile);
    return g_pile;
}

void InputGate::showLigne() const {
    cout << " | ";
}

ostream &operator<<(ostream &out, const InputGate *g) {
    out << g->getName();
    return out;
}
