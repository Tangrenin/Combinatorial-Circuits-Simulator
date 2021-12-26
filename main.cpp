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
    InputGate * a = new InputGate ( 'a') ;
    InputGate * b = new InputGate ( 'b') ;
    Gate * or1 = new OrGate (a , b ) ;
    Gate * and1 = new AndGate (a , b ) ;
    Gate * and2 = new XorGate ( or1 , and1 ) ;
    OutputGate * A = new OutputGate ( and2 ) ;
    cout << "A = ";
    A->afficher();
    for(int i=0;i<A->getPile().size();i++)
    {
        for(int j =0;j<A->getPile()[i].size();j++)
        {
            (A->getPile()[i][j]->showExpression());
            cout <<",";
        }
        cout <<endl;
    }

    cout << "Value : " << A->calculer() << endl;

    //Test 2
    cout << "****************Test 2***************" << endl;
    InputGate * c = new InputGate ( 'c') ;
    Gate * negate1 = new NegateGate (c ) ;
    Gate * or2 = new OrGate (negate1 , b ) ;
    OutputGate * B = new OutputGate ( or2 ) ;
    cout << "B = ";
    B->afficher();
    cout << "Value : " << B->calculer() << endl;

    for(int i=0;i<B->getPile().size();i++)
    {
        for(int j =0;j<B->getPile()[i].size();j++)
        {
            (B->getPile()[i][j]->showExpression());
            cout <<",";
        }
        cout <<endl;
    }
    //Test 3
    cout << "****************Test 3***************" << endl;
    Gate * nand1 = new NandGate (a,b ) ;
    Gate * and3 = new AndGate (nand1 , c ) ;
    OutputGate * C = new OutputGate ( nand1 ) ;
    cout << "C = ";
    C->afficher();

    for(int i=0;i<C->getPile().size();i++)
    {
        for(int j =0;j<C->getPile()[i].size();j++)
        {
            (C->getPile()[i][j]->showExpression());
            cout <<",";
        }
        cout <<endl;
    }
    cout << "Value : " << C->calculer() << endl;

    //Test 3
    cout << "****************Test 4***************" << endl;
    Gate * and4 = new AndGate (a , b ) ;
    Gate * negate2 = new NegateGate(and4);
    OutputGate * D = new OutputGate ( negate2 ) ;
    cout << "D = ";
    D->afficher();
    for(int i=0;i<D->getPile().size();i++)
    {
        for(int j =0;j<D->getPile()[i].size();j++)
        {
            (D->getPile()[i][j]->showExpression());
            cout <<",";
        }
        cout <<endl;
    }


    return 0;
}
