//
// Created by user on 21/12/2021.
//

#ifndef UNTITLED7_NANDGATE_H
#define UNTITLED7_NANDGATE_H

#include "../BinaryGate.h"

class NandGate : public BinaryGate {
private:
    NandGate(const NandGate &n);
public:
    NandGate(Gate *left, Gate *right);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
};

std::ostream &operator<<(std::ostream &out, const NandGate *x);

#endif //UNTITLED7_NANDGATE_H
