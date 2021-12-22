#include <iostream>
#include "InputGate.h"
#include "OrGate.h"
#include "XorGate.h"
#include "AndGate.h"
#include "NegateGate.h"
#include "NandGate.h"

using namespace std;

int main() {
    //Test 1
    cout << "Test 1" << endl;
    InputGate * a = new InputGate ( 'a') ;
    InputGate * b = new InputGate ( 'b') ;
    Gate * or1 = new OrGate (a , b ) ;
    Gate * and1 = new AndGate (a , b ) ;
    Gate * and2 = new XorGate ( or1 , and1 ) ;
    OutputGate * A = new OutputGate ( and2 ) ;
    cout << "A = ";
    A->afficher();
    cout << "Value : " << A->calculer() << endl;

    //Test 2
    cout << "Test 2" << endl;
    InputGate * c = new InputGate ( 'c') ;
    Gate * negate1 = new NegateGate (c ) ;
    Gate * or2 = new OrGate (negate1 , b ) ;
    OutputGate * B = new OutputGate ( or2 ) ;
    cout << "B = ";
    B->afficher();
    cout << "Value : " << B->calculer() << endl;

    //Test 3
    cout << "Test 3" << endl;
    Gate * nand1 = new NandGate (a,b ) ;
    Gate * and3 = new AndGate (nand1 , c ) ;
    OutputGate * C = new OutputGate ( nand1 ) ;
    cout << "C = ";
    C->afficher();
    cout << "Value : " << C->calculer() << endl;
    return 0;
}
