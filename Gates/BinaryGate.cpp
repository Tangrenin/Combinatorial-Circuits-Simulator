//
// Created by user on 20/12/2021.
//

#include "BinaryGate.h"
#include "UnaryGate.h"
#include <queue>
#include "iostream"

using namespace std;

BinaryGate::BinaryGate(Gate *left, Gate *right) : g_left(left), g_right(right) {}

BinaryGate::BinaryGate(const BinaryGate &b) : g_left(b.g_left), g_right(b.g_right) {}

BinaryGate::~BinaryGate() {
    delete g_left;
    delete g_right;
}

// Getters
Gate *BinaryGate::getGateRight() const {
    return g_right;
}

Gate *BinaryGate::getGateLeft() const {
    return g_left;
}

std::string BinaryGate::getType() const {
    return "binary";
}

int BinaryGate::getProfondeur() const {
    return std::max(g_right->getProfondeur(), g_left->getProfondeur()) + 1;
}

std::vector<std::vector<Gate *>> BinaryGate::empileGates() {

    //début : prinicpe similaire que celui d'UnaryGate
    vector<vector<Gate *>> g_pile, pile_bis;
    vector<Gate *> sous_pile;
    queue<Gate *> g_queue;

    g_queue.push(this);

    int i = g_queue.front()->getProfondeur();
    //ici on rajoute déjà le premier élément au vecteur
    sous_pile.push_back(g_queue.front());
    pile_bis.push_back(sous_pile);
    sous_pile.clear();

    Gate *currentGate = g_queue.front();

    while (i > 0) {

        if (currentGate->getType() == "binary") {
            //si le Gate à droite a une profondeur plus importante que celui à gauche,
            //on ajoute d'abord le gate à droite et ensuite le gate à gauche à la pile
            if ((((BinaryGate *) (currentGate))->getGateRight()->getProfondeur()) >
                (((BinaryGate *) (currentGate))->getGateLeft()->getProfondeur())) {
                g_queue.push(((BinaryGate *) (currentGate))->getGateRight());
                sous_pile.push_back(g_queue.back());
                g_queue.push(((BinaryGate *) (currentGate))->getGateLeft());
                sous_pile.push_back(g_queue.back());
            } else {
                //sinon on fait l'inverse
                g_queue.push(((BinaryGate *) (currentGate))->getGateLeft());
                sous_pile.push_back(g_queue.back());
                g_queue.push(((BinaryGate *) (currentGate))->getGateRight());
                sous_pile.push_back(g_queue.back());
            }
        } else {
            g_queue.push(((UnaryGate *) (currentGate))->getGate());
            sous_pile.push_back(g_queue.back());
        }

        //on vérifie qu'il n'y a plus de Gates dans la pile qui ne sont pas des feuilles de l'arbre booléen
        do {
            if (currentGate->getProfondeur() == 0) {
                sous_pile.push_back(nullptr);
                sous_pile.push_back(nullptr);
            }
            g_queue.pop();
            currentGate = g_queue.front();
        } while (currentGate->getProfondeur() == 0 && (g_queue.size() > 1));

        if (i != currentGate->getProfondeur()) {
            i = currentGate->getProfondeur();
            pile_bis.push_back(sous_pile);
            sous_pile.clear();
        }
    }

    //on renverse l'ordre des éléments du vecteur
    for (int j = (int)pile_bis.size() - 1; j >= 0; j--) {
        g_pile.push_back(pile_bis[j]);
    }
    return g_pile;
}

void BinaryGate::showLigne() const {
    cout << " | ";
}

