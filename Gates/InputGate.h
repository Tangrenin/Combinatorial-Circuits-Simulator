//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_INPUTGATE_H
#define UNTITLED7_INPUTGATE_H

#include "OutputGate.h"
#include <string>

class InputGate : public Gate {

private:
    char const name;
    bool value = false;
    int profondeur = 0;
    InputGate(const InputGate &i );

public:
    explicit InputGate(char varName, bool value = false);
    ~InputGate() override;
    // Getters and Setters
    char getName() const;
    int getValue() const;
    int getProfondeur() const override;
    std::string getType() const override;
    void setValue(bool newValue);
    void setProfondeur(int prof) override;
    std::string getText() const override;

    // Class Methods
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
    void showLigne() const override;
    std::vector<std::vector<Gate *>> empileGates() override;
};

std::ostream &operator<<(std::ostream &out, const InputGate *x);

#endif //UNTITLED7_INPUTGATE_H
