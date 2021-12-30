//
// Created by user on 21/12/2021.
//

#ifndef UNTITLED7_NORGATE_H
#define UNTITLED7_NORGATE_H

#include "../BinaryGate.h"

class NorGate : public BinaryGate {
private:
public:
    NorGate(Gate *left, Gate *right);
    void afficher() override;
    int calculer() override;
    void showExpression() override;
};

std::ostream &operator<<(std::ostream &out, const NorGate *x);

#endif //UNTITLED7_NORGATE_H
