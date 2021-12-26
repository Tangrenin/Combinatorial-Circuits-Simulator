//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_ORGATE_H
#define UNTITLED7_ORGATE_H

#include "../BinaryGate.h"

class OrGate : public BinaryGate {
private:
public:
    OrGate(Gate* left, Gate* right);
    void afficher() override;
    int calculer() override;
    void showExpression() override;
};
std::ostream& operator<<(std::ostream& out, const OrGate *x);

#endif //UNTITLED7_ORGATE_H
