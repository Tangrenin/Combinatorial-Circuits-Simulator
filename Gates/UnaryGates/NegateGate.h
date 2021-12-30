//
// Created by user on 21/12/2021.
//

#ifndef UNTITLED7_NEGATEGATE_H
#define UNTITLED7_NEGATEGATE_H

#include "../UnaryGate.h"

class NegateGate : public UnaryGate {
private:
public:
    NegateGate(Gate *main);
    void afficher() override;
    int calculer() override;
    void showExpression() override;
};

std::ostream &operator<<(std::ostream &out, const NegateGate *x);

#endif //UNTITLED7_NEGATEGATE_H
