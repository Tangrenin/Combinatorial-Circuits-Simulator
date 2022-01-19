//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_ANDGATE_H
#define UNTITLED7_ANDGATE_H

#include "../BinaryGate.h"

class AndGate : public BinaryGate {
private:
    AndGate(const AndGate &a);
public:
    AndGate(Gate *left, Gate *right);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
    std::string getText() const override;
};

std::ostream &operator<<(std::ostream &out, const AndGate *x);


#endif //UNTITLED7_ANDGATE_H
