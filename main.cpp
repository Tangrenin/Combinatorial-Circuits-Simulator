#include <iostream>
#include "Gates/InputGate.h"
#include "Gates/BinaryGates/OrGate.h"
#include "Gates/BinaryGates/XorGate.h"
#include "Gates/BinaryGates/AndGate.h"
#include "Gates/UnaryGates/NegateGate.h"
#include "Gates/BinaryGates/NandGate.h"

using namespace std;

int main() {
    //Test 1
    cout << "****************Test 1***************" << endl;
    auto *a = new InputGate('a');
    auto *b = new InputGate('b');
    Gate *or1 = new OrGate(a, b);
    Gate *and1 = new AndGate(a, b);
    Gate *and2 = new XorGate(or1, and1);
    auto *A = new OutputGate(and2);
    // auto *A_bis = new OutputGate("xor(or(a,b),and(a,b)");
    A->afficher();
    A->showOutput();


    //Test 2
    cout << "****************Test 2***************" << endl;
    auto *c = new InputGate('c');
    Gate *negate1 = new NegateGate(c);
    Gate *or2 = new OrGate(negate1, b);
    auto *B = new OutputGate(or2);
    B->afficher();

    B->showOutput();
    //Test 3
    cout << "****************Test 3***************" << endl;
    Gate *nand1 = new NandGate(a, b);
    Gate *and3 = new AndGate(nand1, c);
    auto *C = new OutputGate(and3);
    C->afficher();

    for (int i = 0; i < C->getPile().size(); i++) {
        for (int j = 0; j < C->getPile()[i].size(); j++) {
            (C->getPile()[i][j]->showExpression());
            cout << ",";
        }
        cout << endl;
    }

    C->showOutput();

    // Test 4
    cout << "****************Test 4***************" << endl;
    Gate *and4 = new AndGate(a, b);
    Gate *negate2 = new NegateGate(and4);
    auto *D = new OutputGate(negate2);
    D->afficher();
    D->showOutput();

    // Test 5
    cout << "****************Test 5***************" << endl;
    auto *a1 = new InputGate('a');
    auto *b1 = new InputGate('b');
    auto *c1 = new InputGate('c');
    auto *d1 = new InputGate('d');
    Gate *or5 = new OrGate(a1, b1);
    Gate *xor1 = new XorGate(c1, or5);
    Gate *or6 = new OrGate(d1, xor1);

    auto *E = new OutputGate(or6);
    E->afficher();
    E->showOutput();

    return 0;
}
