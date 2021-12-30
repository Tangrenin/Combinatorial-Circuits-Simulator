//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_GATE_H
#define UNTITLED7_GATE_H

#include <string>
#include <vector>

class Gate {
private:
public:
    virtual ~Gate();
    // Getters
    virtual int getProfondeur() const = 0;
    virtual std::string getType() const = 0;
    // Class Methods
    virtual void afficher() = 0;
    virtual void showLigne() = 0;
    virtual int calculer() = 0;
    virtual void showExpression() = 0;
    virtual std::vector<std::vector<Gate *>> empileGates() = 0;
};


#endif //UNTITLED7_GATE_H
