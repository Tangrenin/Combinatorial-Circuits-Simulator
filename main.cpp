#include <iostream>
#include "InputGate.h"
#include "OrGate.h"
#include "XorGate.h"
#include "AndGate.h"

using namespace std;

int main() {
    InputGate * a = new InputGate ( 'a') ;
    InputGate * b = new InputGate ( 'a') ;
    Gate * or1 = new OrGate (a , b ) ;
    Gate * and1 = new AndGate (a , b ) ;
    Gate * and2 = new XorGate ( or1 , and1 ) ;
    OutputGate * A = new OutputGate ( and2 ) ;
    cout << "A = ";
    A->afficher();
    cout << A->calculer();
    return 0;
}
