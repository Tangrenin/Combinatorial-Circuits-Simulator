//
// Created by user on 20/12/2021.
//

#include "OutputGate.h"
#include "InputGate.h"
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
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
     * ou à partir d'un fichier si on lui passe une string contenant '.txt'
     */
    if (g_main_text.find(".txt") != string::npos) { // Si on reçoit un nom de fichier, en extraire l'expression textuelle
        ifstream in(g_main_text);
        string line;
        for (int i = 0; i < 3; i++) //skipping the first three lines
            getline(in, line);
        getline(in, line);
        g_main_text = line;
        name = g_main_text[0];
    }

    // Creer le circuit à partir de expression textuelle
    g_main = generateByExpr(g_main_text.substr(4)); // On enlève la partie "A = " de l'expression textuelle
    if (g_main!= nullptr)
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
    if (g_main!= nullptr) {
        /*
         * Affichage graphique du circuit
         * */
        int debut_ligne = 0; //On fixe les indices qui nous permettront de gérer les espaces en début de ligne et entre deux Gates
        int espace_milieu = 1;
        for (int i = 0; i < g_pile.size(); i++) {
            //On itère le procédé sur chaque étage de l'expression booléenne
            //On part de l'étage 0
            cout << string(debut_ligne, ' '); //On ajoute le nombre nécessaire d'espaces en début de ligne
            /*
             * On affiche d'abord la forme textuelle des Gates
             * Ensuite on va à la ligne, et on affiche pour chaque Gate la ligne représentant la sortie correspondante
             */
            for (auto gate: g_pile[i]) {
                gate->showExpression(); //forme textuelle
                cout << string(espace_milieu, ' ');
            }
            cout << endl;
            cout << string(debut_ligne, ' ');
            for (auto gate: g_pile[i]) {
                gate->showLigne(); //les lignes représentant les sorties
                cout << string(espace_milieu, ' ');
            }
            cout << endl;
            //Pour chaque Gate qui ne fait pas parti du dernier étage de l'arbre booléen
            //On formate l'expression en rajoutant des '*'
            if (i != g_pile.size() - 1) {
                cout << string(debut_ligne + 1, ' ');
                //si l'étage ne contient qu'un seul Gate
                if (g_pile[i].size() == 1) {
                    cout << string((espace_milieu / 2) + 3, '*') << endl;
                    cout << string(debut_ligne + 2 * i + 3, ' ');
                    cout << '|';
                }
                    //sinon
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
                //on met à jour nos indices gérant les espaces
                debut_ligne += 2 * i + 2;
                espace_milieu = debut_ligne + 3;
            }
        }
        cout << string(debut_ligne + 1, ' ') << name << "\n\n";
        cout << calculerOutput() << "\n\n";
    }else{
        cout << "circuit non coherent";
    }
    cout << endl;
}

void OutputGate::outputToText() const {
    if (g_main !=nullptr){
        cout << name << " = ";
        g_main->afficher();
    }
    else
        cout << "circuit non coherent";
    cout << endl;
}

int OutputGate::calculerOutput() const {
    cout << "Ouput value :  " ;
    if (g_main!= nullptr){
        return g_main->calculer();
    }
    return -1;
}

Gate *OutputGate::generateByExpr(string expr) {
    // On vérifie si l'expression une variable input
    if (expr.size() == 1){
        return new InputGate(expr[0]);
    }
    else { // Si l'expression est une porte logique
        string gateType = expr.substr(0, expr.find('('));
        //rendre la méthode insensible à la casse
        for (int i = 0; i < gateType.length(); i++) {
            gateType[i] = tolower(gateType[i]);
        }
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
            else{
                return nullptr;
            }
        }
    }
    return nullptr;

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
    if (virgulePos!=0){
        args.first = expr.substr(0, virgulePos);
        args.second = expr.substr(virgulePos + 1, expr.size());
    }else{
        args.second = expr.substr(virgulePos, expr.size());
    }
    return args;
}

void OutputGate::saveInFile() const {
    /*
     * Save circuit in a file in the "saved-circuits" directory, both text expression and graphic display
     */
    // Creating File...
    string outputDirectoryName = "saved-circuits";
    string fileName = "circuit-";
    fileName += name;
    fileName += ".txt";
    ofstream out("saved-circuits/" + fileName);
    // Redirecting cout stream to our file
    streambuf *coutbuf = cout.rdbuf(); // saving old buffer
    std::cout.rdbuf(out.rdbuf());
    cout << "======== Circuit combinatoire ========\n" << endl;
    cout << "Expression textuelle du circuit : " << endl;
    outputToText();
    cout << "\nAffichage graphique du circuit : \n";
    showOutput();

    // Restoring stream to standard output
    cout.rdbuf(coutbuf);
    out.close();
}
