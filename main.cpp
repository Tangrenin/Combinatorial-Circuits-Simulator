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
    A->outputToText();
    A->showOutput();


    //Test 2
    cout << "****************Test 2***************" << endl;
    cout << "** Creation d'un circuit assymetrique avec une branche plus longue **\n\n";
    auto *c = new InputGate('c', true);
    Gate *negate1 = new NegateGate(c);
    Gate *or2 = new OrGate(negate1, b);
    auto *B = new OutputGate(or2);
    B->outputToText();

    B->showOutput();

    //Test 3
    cout << "****************Test 3***************" << endl;
    cout << "** Creation d'un circuit assymetrique avec une deux UnaryGates imbriques **\n\n";
    auto *d = new InputGate('d', true);
    Gate *negate2 = new NegateGate(d);
    Gate *negate2bis = new NegateGate(negate2);
    auto *C = new OutputGate(negate2bis);
    C->outputToText();

    C->showOutput();

    //Test 4
    cout << "****************Test 4***************" << endl;
    cout << "** Etude du fonctionnement de la pile permettant l'affichage graphique **\n\n";
    Gate *nand1 = new NandGate(a, b);
    Gate *and3 = new AndGate(nand1, c);
    auto *D = new OutputGate(and3);
    D->outputToText();
    D->showOutput();
    cout << "\nAffichage des elements de la pile...\n";
    for (int i = 0; i < (int)D->getPile().size(); i++) {
        for (int j = 0; j < (int)D->getPile()[i].size(); j++) {
            if (D->getPile()[i][j] != nullptr) {
                (D->getPile()[i][j]->showExpression());
                cout << ",";
            }
        }
        cout << endl;
    }
    cout << D->getName() << "\n\n";


    // Test 5
    cout << "****************Test 5***************" << endl;
    cout << "** Encore un exemple de circuit pour la route... **\n\n";
    Gate *and4 = new AndGate(a, b);
    Gate *negate3 = new NegateGate(and4);
    auto *E = new OutputGate(negate3);
    E->outputToText();
    E->showOutput();

    // Test 6
    cout << "****************Test 6***************" << endl;
    cout << "** Affichage d'un gros circuit assymetrique **\n";
    cout << "** On verifie que tout s'affiche correctement avec le bon alignement **\n\n";
    auto *a1 = new InputGate('a', true);
    auto *b1 = new InputGate('b');
    auto *c1 = new InputGate('c');
    auto *d1 = new InputGate('d', true);
    auto *e1 = new InputGate('e', true);
    Gate *and5 = new AndGate(a1, b1);
    Gate *or5 = new OrGate(e1, and5);
    Gate *xor1 = new XorGate(or5, c1);
    Gate *nor1 = new NorGate(d1, xor1);

    auto *F = new OutputGate(nor1);
    F->outputToText();
    F->showOutput();

    // Test 7 : Creer un circuit à partir d'une expression textuelle
    cout << "****************Test 7***************" << endl;
    cout << "** Creation d'un circuit a partir d'une expression textuelle : F = nor(or(a,b),and(a,b)) **\n\n";
    auto *Fbis = new OutputGate("F = Nor(or(a,b),and(a,b))");
    Fbis->outputToText();
    Fbis->showOutput();

    cout << "On remarque que la creation du circuit a bien fonctionne malgre le N majuscule de 'Nor'.\n";
    cout
            << "De plus, vous pouvez essayer de modifier l'expression textuelle en quelque chose d'incoherent pour voir ce qu'il advient \n\n";

    // Test 8 : Ecriture dans un fichier
    cout << "****************Test 8***************" << endl;
    cout
            << "** Sauvegarde d'un circuit dans un fichier. Allez voir par vous-meme dans le dossier saved-circuits **\n\n";
    Fbis->saveInFile();

    // Test 9 : Lecture d'un fichier
    cout << "****************Test 9***************" << endl;
    cout << "** Creation d'un circuit a partir d'un fichier de sauvegarde de circuit **\n\n";
    auto *Fbbis = new OutputGate("saved-circuits/circuit-F.txt");
    Fbbis->outputToText();
    Fbbis->showOutput();

    cout << "** Creation d'une copie du circuit que l'on vient de creer **\n\n";
    auto *G = new OutputGate(*Fbbis);
    G->outputToText();
    G->showOutput();

    // Test 10 : Creer un circuit à partir d'une expression textuelle
    cout << "****************Test 10***************" << endl;
    cout << "** Creation d'un circuit a partir d'une expression textuelle : H = negate(or(and(a,b),c)) **\n\n";
    auto *Z = new OutputGate("Z = negate(or(and(a,b),c))");
    Z->outputToText();
    Z->showOutput();
    Z->saveInFile();

    // Test 11 : Creer un circuit assymétrique et étudier sa valeur de vérité ainsi que sa copie
    cout << "****************Test 11***************" << endl;
    cout << "** Creation d'un circuit assymetrique et etude de sa valeur de verite ainsi que de sa copie**\n\n";
    auto *f = new InputGate('f');

    Gate *nand2 = new NandGate(a, f);
    Gate *xor2 = new XorGate(nand2, c);

    auto *H = new OutputGate(xor2);
    auto *I = new OutputGate(*H);

    H->outputToText();
    H->showOutput();
    //On affiche une copie du circuit
    cout << "Copie du circuit : \n\n";
    I->outputToText();
    I->showOutput();

    //Modification des valeurs du InputGate de H
    a->setValue(true);
    f->setValue(true);

    cout << "Circuit apres modification des valeurs de verite des InputGate du circuit original: \n\n";
    H->outputToText();
    H->showOutput();
    cout << "Copie du circuit : On remarque que la modification des InputGate ne l'a pas affecte \n\n";
    I->outputToText();
    I->showOutput();

    // Test 11 : Affichage de circuits plus complexes
    cout << "****************Test 12***************" << endl;
    cout << "** Affichage de circuits plus complexes **\n\n";

    auto *J = new OutputGate(
            new OrGate(new XorGate(new OrGate(new InputGate('a'), new InputGate('b')), new InputGate('c')),
                       new XorGate(new InputGate('a'), new NegateGate(new InputGate('d')))));
    J->outputToText();
    J->showOutput();

    auto *K = new OutputGate(
            new OrGate(new XorGate(new OrGate(new InputGate('a'), new InputGate('b')), new InputGate('c')),
                       new XorGate(new InputGate('a'), new NorGate(new InputGate('d'), new InputGate('e')))));
    K->outputToText();
    K->showOutput();

    auto *L = new OutputGate(new AndGate(new OrGate(e1,f),new OrGate(b,new AndGate(e1,new OrGate(a,b)))));

    L->showOutput();
    cout << "\n====== Merci de votre attention ! ======\n\n";
    return 0;
}
