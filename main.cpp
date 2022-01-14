#include <iostream>
#include "Gates/InputGate.h"
#include "Gates/BinaryGates/OrGate.h"
#include "Gates/BinaryGates/XorGate.h"
#include "Gates/BinaryGates/AndGate.h"
#include "Gates/UnaryGates/NegateGate.h"
#include "Gates/BinaryGates/NandGate.h"
#include "Gates/BinaryGates/NorGate.h"

using namespace std;

int main() {
    cout << "========== Simulation de circuits combinatoires ==========\n\n";
    cout << "Par Madeleine Schmit et Quentin Didier\n";
    cout << "Github repository at : https://github.com/Tangrenin/Combinatorial-Circuits-Simulator\n\n";
    cout << "Ci-dessous, la demonstration du fonctionnement des simulations via quelques tests.\n";
    cout << "Vous pouvez modifier les valeurs de verite des variables ou ajouter des portes de votre choix.\n";
    cout << "Sinon, asseyez-vous confortablement et observez les tests se derouler sous vos yeux...\n\n";
    //Test 1
    cout << "****************Test 1***************" << endl;
    cout << "** Creation d'un circuit simple et son affichage textuel et graphique **\n\n";
    auto *a = new InputGate('a');
    auto *b = new InputGate('b', true);
    Gate *or1 = new OrGate(a, b);
    Gate *and1 = new AndGate(a, b);
    Gate *and2 = new XorGate(or1, and1);
    auto *A = new OutputGate(and2);
    A->afficherOutput();
    A->showOutput();


    //Test 2
    cout << "****************Test 2***************" << endl;
    cout << "** Creation d'un circuit assymetrique avec une branche plus longue **\n\n";
    auto *c = new InputGate('c', true);
    Gate *negate1 = new NegateGate(c);
    Gate *or2 = new OrGate(negate1, b);
    auto *B = new OutputGate(or2);
    B->afficherOutput();

    B->showOutput();
    //Test 3
    cout << "****************Test 3***************" << endl;
    cout << "** Etude du fonctionnement de la pile permettant l'affichage graphique **\n\n";
    Gate *nand1 = new NandGate(a, b);
    Gate *and3 = new AndGate(nand1, c);
    auto *C = new OutputGate(and3);
    C->afficherOutput();
    cout << "\nAffichage des elements de la pile...\n";
    for (int i = 0; i < C->getPile().size(); i++) {
        for (int j = 0; j < C->getPile()[i].size(); j++) {
            (C->getPile()[i][j]->showExpression());
            cout << ",";
        }
        cout << endl;
    }
    cout << C->getName() << "\n\n";


    // Test 4
    cout << "****************Test 4***************" << endl;
    cout << "** Encore un exemple de circuit pour la route... **\n\n";
    Gate *and4 = new AndGate(a, b);
    Gate *negate2 = new NegateGate(and4);
    auto *D = new OutputGate(negate2);
    D->afficherOutput();
    D->showOutput();

    // Test 5
    cout << "****************Test 5***************" << endl;
    cout << "** Affichage d'un gros circuit assymetrique **\n";
    cout << "** On verifie que tout s'affiche correctement avec le bon alignement **\n\n";
    auto *a1 = new InputGate('a', true);
    auto *b1 = new InputGate('b');
    auto *c1 = new InputGate('c');
    auto *d1 = new InputGate('d', true);
    Gate *or5 = new OrGate(a1, b1);
    Gate *xor1 = new XorGate(c1, or5);
    Gate *nor1 = new NorGate(d1, xor1);

    auto *E = new OutputGate(nor1);
    E->afficherOutput();
    E->showOutput();

    // Test 6 : Creer un circuit à partir d'une expression textuelle
    cout << "****************Test 6***************" << endl;
    cout << "** Creation d'un circuit a partir d'une expression textuelle : F = nor(or(a,b),and(a,b)) **\n\n";
    auto *F = new OutputGate("F = nor(or(a,b),and(a,b))");
    F->afficherOutput();
    F->showOutput();

    // Test 7 : Ecriture dans un fichier
    cout << "****************Test 7***************" << endl;
    cout << "** Sauvegarde d'un circuit dans un fichier. Allez voir par vous-meme dans le dossier saved-circuits **\n\n";
    F->saveInFile();

    // Test 8 : Lecture d'un fichier
    cout << "****************Test 8***************" << endl;
    cout << "** Creation d'un circuit a partir d'un fichier de sauvegarde de circuit **\n\n";
    auto *Fbis = new OutputGate("saved-circuits/circuit-F.txt");
    Fbis->afficherOutput();
    Fbis->showOutput();

    cout << "\n====== Merci de votre attention ! ======\n\n";
    return 0;
}
