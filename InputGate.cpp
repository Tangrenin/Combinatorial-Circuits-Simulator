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


