//
// Created by user on 20/12/2021.
//

#include "UnaryGate.h"
#include <queue>
#include "iostream"

using namespace std;


UnaryGate::UnaryGate(Gate *main) : g_main(main) {
    profondeur = g_main->getProfondeur() + 1;
}

UnaryGate::UnaryGate(const UnaryGate &u) : g_main(u.g_main), profondeur(u.profondeur) {}

UnaryGate::~UnaryGate() {
    delete g_main;
}

Gate *UnaryGate::getGate() const {
    return g_main;
}

std::string UnaryGate::getType() const {
    return "unary";
}

int UnaryGate::getProfondeur() const {
    return profondeur;
}

void UnaryGate::setProfondeur(int prof) {
    profondeur = prof;
}

/*
 * crée un vecteur de Gates à partir d'un OutputGate
 * permet de retrouver facilement les Gates individuels qui constituent l'OutputGate
 */
std::vector<std::vector<Gate *>> UnaryGate::empileGates() {

    vector<vector<Gate *>> g_pile, pile_bis;
    //le vecteur qui représente un étage
    vector<Gate *> sous_pile;
    //la pile qui contient les gates d'un même étage
    queue<Gate *> g_queue;


    g_queue.push(this); //On rajoute à la pile le premier élément du OutputGate

    int i = g_queue.front()->getProfondeur() +
            1; // i représente la profondeur + 1 de l'élément qu'on vient d'ajouter à la pile
    sous_pile.push_back(g_queue.front()); // on rajoute la pile au premier sous-vecteur

    while (i > 0) {
        Gate *currentGate = g_queue.front();
        //Ici on vérifie si on a changé de profondeur
        if (i > currentGate->getProfondeur()) {
            //on change de profondeur et on ajoute le sous-vecteur courant au vecteur final
            i = currentGate->getProfondeur();
            pile_bis.push_back(sous_pile);
            sous_pile.clear();
        }
        if ((currentGate->getType() == "binary") || (currentGate->getType() == "input")) {
            //si c'est un gate binaire on fait appel à la fonction empileGates() pour les gates binaire
            g_pile = currentGate->empileGates();
            g_pile.resize(g_pile.size() - 1);
            break;
        } else {
            //sinon on rajoute le Gate courant à la pile et au sous-vecteur courant
            g_queue.push(((UnaryGate *) (currentGate))->getGate());
            sous_pile.push_back(g_queue.back());
        }
        g_queue.pop();
    }
    //on inverse les éléments de la pile, pour commencer par la profondeur 0
    for (int i = pile_bis.size() - 1; i >= 0; i--) {
        g_pile.push_back(pile_bis[i]);
    }
    return g_pile;
}

void UnaryGate::showLigne() const {
    cout << " | ";
}


