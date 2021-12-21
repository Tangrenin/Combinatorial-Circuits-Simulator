//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_INPUTGATE_H
#define UNTITLED7_INPUTGATE_H
#include "OutputGate.h"
#include <string>

class InputGate : public Gate {
private:
    int value = 0;
    char const input;
public:
    InputGate(char input);
    char getInput() const;
    int getValue() const;

    void afficher() override;
    int calculer() override;
};


#endif //UNTITLED7_INPUTGATE_H
