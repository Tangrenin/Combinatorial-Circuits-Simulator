//
// Created by user on 21/12/2021.
//

#ifndef UNTITLED7_NEGATEGATE_H
#define UNTITLED7_NEGATEGATE_H

#include "../UnaryGate.h"

class NegateGate : public UnaryGate {
private:
    NegateGate(const NegateGate &n );
public:
    explicit NegateGate(Gate *main);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
};

std::ostream &operator<<(std::ostream &out, const NegateGate *x);

#endif //UNTITLED7_NEGATEGATE_H
