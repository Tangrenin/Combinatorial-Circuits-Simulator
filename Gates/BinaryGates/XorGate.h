//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_XORGATE_H
#define UNTITLED7_XORGATE_H

#include "../BinaryGate.h"

class XorGate : public BinaryGate {
private:
    XorGate(const XorGate &x );
public:
    XorGate(Gate *left, Gate *right);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
    std::string getText() const override;
};

std::ostream &operator<<(std::ostream &out, const XorGate *x);

#endif //UNTITLED7_XORGATE_H
