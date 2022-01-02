//
// Created by user on 20/12/2021.
//

#include "OutputGate.h"
#include "InputGate.h"
#include <iostream>
#include <string>
#include <queue>
#include <utility>
#include "UnaryGates/NegateGate.h"
#include "BinaryGates/AndGate.h"
#include "BinaryGates/NandGate.h"
#include "BinaryGates/NorGate.h"
#include "BinaryGates/OrGate.h"
#include "BinaryGates/XorGate.h"

using namespace std;

char OutputGate::nameTracker = 'A';

OutputGate::OutputGate(Gate *main) : g_main(main), g_pile(vector<vector<Gate *>>()), name(nameTracker++) {
    g_pile = g_main->empileGates();
}

OutputGate::OutputGate(string mainText) : g_main(nullptr), g_pile(vector<vector<Gate *>>()),
g_main_text(move(mainText)), name(g_main_text[0]) {
    /*
     * Reconstruit un circuit à partir d'une expression textuelle
     * Exemple : A = xor(or(a,b),and(a,b)
     */
    g_main = generateByExpr(g_main_text.substr(4)); // On enlève la partie "A = " de l'expression textuelle
    g_pile = g_main->empileGates();
}

OutputGate::~OutputGate() {
    delete g_main;
}


// Getters
Gate *OutputGate::getMainGate() const{
    return g_main;
}

string OutputGate::getMainText() const {
    return g_main_text;
}

vector<vector<Gate *>> OutputGate::getPile() const {
    return g_pile;
}

char OutputGate::getName() const {
    return name;
}

void OutputGate::showOutput() const {
    /*
     * Affichage graphique du circuit
     * */
    int debut_ligne = 0;
    int espace_milieu = 1;
    for (int i = 0; i < g_pile.size(); i++) {
        cout << string(debut_ligne, ' ');
        for (auto gate : g_pile[i]) {
            gate->showExpression();
            cout << string(espace_milieu, ' ');
        }
        cout << endl;
        cout << string(debut_ligne, ' ');
        for (auto gate : g_pile[i]) {
            gate->showLigne();
            cout << string(espace_milieu, ' ');
        }
        cout << endl;

        if (i != g_pile.size() - 1) {
            cout << string(debut_ligne + 1, ' ');
            if (g_pile[i].size() == 1) {
                cout << string((espace_milieu / 2) + 3, '*') << endl;
                cout << string(debut_ligne + 2 * i + 3, ' ');
                cout << '|';
            }
            else {
                for (int k = 0; k < g_pile[i].size() / 2; k++) {
                    cout << string((espace_milieu / 2) + 2, '*');
                    cout << string(1, ' ');
                    cout << string((espace_milieu / 2) + 2, '*');
                    cout << string(espace_milieu + 2, ' ');
                }
                cout << endl;
                for (int k = 0; k < g_pile[i].size() / 2; k++) {
                    cout << string(debut_ligne + 2 * i + 3, ' ');
                    cout << "|";
                    cout << string(espace_milieu + 3, ' ');
                }
            }
            cout << endl;
            debut_ligne += 2 * i + 2;
            espace_milieu = debut_ligne + 3;
        }
    }
    cout << string(debut_ligne + 1, ' ') << name << "\n\n";
    cout << "Ouput value :  "  << calculer() << "\n\n";
}

void OutputGate::afficher() const {
    cout << name << " = ";
    g_main->afficher();
    cout << endl;
}

int OutputGate::calculer() const {
    return g_main->calculer();
}

Gate *OutputGate::generateByExpr(string expr) {
    // On vérifie si l'expression une variable input
    if (expr.size() == 1){
        return new InputGate(expr[0]);
    }
    else { // Si l'expression est une porte logique
        string gateType = expr.substr(0, expr.find('('));
        pair<string, string> gateArgs =
                parseExprIntoArgs(expr.substr(expr.find('(') + 1, expr.size() - expr.find('(') - 2));
        if (gateArgs.first.empty()) { // Unary gate
            if (gateType == "negate")
                return new NegateGate(generateByExpr(gateArgs.second));
        }
        else { // Binary gates
            if (gateType == "and")
                return  new AndGate(generateByExpr(gateArgs.first),generateByExpr(gateArgs.second));
            else if (gateType == "nand")
                return  new NandGate(generateByExpr(gateArgs.first),generateByExpr(gateArgs.second));
            else if (gateType == "nor")
                return  new NorGate(generateByExpr(gateArgs.first),generateByExpr(gateArgs.second));
            else if (gateType == "or")
                return  new OrGate(generateByExpr(gateArgs.first),generateByExpr(gateArgs.second));
            else if (gateType == "xor")
                return  new XorGate(generateByExpr(gateArgs.first),generateByExpr(gateArgs.second));
        }
    }

}

pair<string, string> OutputGate::parseExprIntoArgs(string expr) {
    /*
     * parse an expression like or( -> "d,xor(c,or(a,b))" <- )
     * into a pair containing both arguments of the function
     * if first member of pair is empty, it means the function is unary
     */
    pair<string, string> args;
    int virgulePos(0);
    int parenthesisCounter = 0;
    // Se charge de trouver la virgule principale séparant l'expression, si c'est une porte binaire.
    for (int i(0) ; i < expr.size() ; i++){
        if (expr[i] == '(')
            parenthesisCounter++;
        else if (expr[i] == ')')
            parenthesisCounter--;
        else if ((expr[i] == ',') && (parenthesisCounter == 0))
            virgulePos = i;
    }
    args.first = expr.substr(0, virgulePos);
    args.second = expr.substr(virgulePos + 1, expr.size());
    return args;
}
