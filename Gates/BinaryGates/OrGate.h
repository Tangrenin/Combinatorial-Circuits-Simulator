//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_ORGATE_H
#define UNTITLED7_ORGATE_H

#include "../BinaryGate.h"

class OrGate : public BinaryGate {
private:
    OrGate(const OrGate &o );
public:
    OrGate(Gate *left, Gate *right);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
    std::string getText() const override;
};

std::ostream &operator<<(std::ostream &out, const OrGate *x);

#endif //UNTITLED7_ORGATE_H
