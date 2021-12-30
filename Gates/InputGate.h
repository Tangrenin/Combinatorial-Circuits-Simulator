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
    int profondeur = 0;
    char const input;
public:
    InputGate(char input, bool value = 0);
    // Getters
    char getInput() const;
    int getValue() const;
    void setValue(bool newValue);
    int getProfondeur() const override;
    std::string getType() const override;

    // Class Methods
    void afficher() override;
    int calculer() override;
    void showExpression() override;
    void showLigne() override;
    std::vector<std::vector<Gate *>> empileGates() override;
};

std::ostream &operator<<(std::ostream &out, const InputGate *x);

#endif //UNTITLED7_INPUTGATE_H
