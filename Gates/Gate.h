//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_GATE_H
#define UNTITLED7_GATE_H

#include <string>
#include <vector>

class Gate {
protected:
    Gate();
    Gate(const Gate &g);
public:
    virtual ~Gate();

    // Getters
    virtual int getProfondeur() const = 0;
    virtual std::string getType() const = 0;

    // Class Methods
    virtual void afficher() const = 0;
    virtual void showLigne() const = 0;
    virtual int calculer() const = 0;
    virtual void showExpression() const = 0;
    virtual std::vector<std::vector<Gate *>> empileGates() = 0;
};


#endif //UNTITLED7_GATE_H
