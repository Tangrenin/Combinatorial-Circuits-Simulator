//
// Created by user on 20/12/2021.
//

#include "OutputGate.h"
#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

OutputGate::OutputGate(Gate *main) : g_main(main), g_pile(vector<vector<Gate *>>()) {
    g_pile = g_main->empileGates();
}

OutputGate::OutputGate(string mainText) : g_main(nullptr), g_main_text(move(mainText)) {}

string OutputGate::getMainText() {
    return g_main_text;
}

OutputGate::~OutputGate() {
    delete g_main;
}

// Getters
Gate *OutputGate::getMainGate() {
    return g_main;
}

vector<vector<Gate *>> OutputGate::getPile() {
    return g_pile;
}

// Fonction bizarre et inutile
//void OutputGate::textToGatePile() {
//    string inputCopy = g_main_text;
//    vector<vector<string>> gates_text;
//    vector<string> sous_text;
//    int pos;
//    while ((pos = inputCopy.find('(')) >= 0) {
//        sous_text.push_back(inputCopy.substr(0, pos));
//        inputCopy.erase(0, pos + 1);
//        inputCopy.erase(inputCopy.size() - 1, 1);
//    }
//    for (int i = 0; i < gates_text.size(); i++) {
//        for (string s: gates_text[i]) {
//            cout << s << endl;
//        }
//    }
//}

void OutputGate::showOutput() const {
    int debut_ligne = 0;
    int espace_milieu = 1;
    for (int i = 0; i < g_pile.size(); i++) {
        cout << string(debut_ligne, ' ');
        for (int j = 0; j < g_pile[i].size(); j++) {
            g_pile[i][j]->showExpression();
            cout << string(espace_milieu, ' ');
        }
        cout << endl;
        cout << string(debut_ligne, ' ');
        for (int j = 0; j < g_pile[i].size(); j++) {
            g_pile[i][j]->showLigne();
            cout << string(espace_milieu, ' ');
        }
        cout << endl;
        if (i != g_pile.size() - 1) {
            cout << string(debut_ligne + 1, ' ');
            if (g_pile[i].size() == 1) {
                cout << string((espace_milieu / 2) + 3, '*') << endl;
                cout << string(debut_ligne + 2 * i + 3, ' ');
                cout << '|';
            } else {
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
        }
        debut_ligne += 2 * i + 2;
        espace_milieu = debut_ligne + 3;
        cout << endl;
    }

}

void OutputGate::afficher() {
    g_main->afficher();
    cout << endl;
}

int OutputGate::calculer() {
    return g_main->calculer();
}


/**
* if (g_pile[i].size()==2){
            if ((g_pile[i][0]->getType()=="binary") && (g_pile[i][1]->getType())!="binary"){
                cout <<" |  | " ;
                if (g_pile[i][1]->getType()=="unary")
                    cout <<"| " <<endl;
                else
                    cout <<"  " <<endl;
            }
            else if ((g_pile[i][0]->getType()=="binary") && (g_pile[i][1]->getType())=="binary"){
                cout <<" |  | " ;
                cout <<"|  |" <<endl;
            }
            else if ((g_pile[i][0]->getType()!="binary") && (g_pile[i][1]->getType())=="binary"){
                if (g_pile[i][0]->getType()=="unary")
                    cout <<" |" ;
                else
                    cout <<"  ";
                cout <<"|  |" <<endl;
            }
            else {
                if ((g_pile[i][0]->getType()!="unary") && (g_pile[i][1]->getType())!="unary"){
                    cout <<""<<endl;
                }
                else{
                    cout << " | ";
                    cout << " | " << endl;
                }
            }

            for (int k=0 ; k<=i; k++){
                cout <<" ";
            }

            if (i==0){
                cout <<"  " ;
                g_pile[0][0]->showExpression();
                cout <<"  " ;
                g_pile[0][1]->showExpression();
            }else {
                cout << " ";
                g_pile[i][0]->showExpression();
                cout << " ";
                g_pile[i][1]->showExpression();
            }

        }else{
            if ((g_pile[i][0]->getType()=="binary")){
                cout <<" |  |" <<endl;
            }
            else{
                cout <<" | " <<endl;
            }
            for (int k=0 ; k<=i; k++){
                cout <<" ";
            }
            cout << "  ";
            g_pile[i][0]->showExpression();
        }
        cout <<endl;
    }
*/