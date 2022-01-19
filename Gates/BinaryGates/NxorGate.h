//
// Created by user on 14/01/2022.
//

#ifndef UNTITLED7_NXORGATE_H
#define UNTITLED7_NXORGATE_H

#include "../BinaryGate.h"
class NxorGate : public BinaryGate {
private:
    NxorGate(const NxorGate &n);
public:
    NxorGate(Gate *left, Gate *right);
    void afficher() const override;
    int calculer() const override;
    void showExpression() const override;
    std::string getText() const override;
};

std::ostream &operator<<(std::ostream &out, const NxorGate *x);


#endif //UNTITLED7_NXORGATE_H
