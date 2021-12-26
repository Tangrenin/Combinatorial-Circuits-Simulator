//
// Created by user on 20/12/2021.
//

#include "UnaryGate.h"
#include <queue>

using namespace std;

Gate* UnaryGate::getGate() const{
    return g_main;
}

UnaryGate::UnaryGate(Gate* main): g_main(main){}

std::string UnaryGate::getType() const{
    return "unary";
}

int UnaryGate::getProfondeur() const {
    return g_main->getProfondeur()+1;
}


std::vector<std::vector<Gate *>> UnaryGate::empileGates() {
    vector<vector<Gate*>> g_pile;
    queue<Gate *> g_queue;
    vector<Gate*> sous_pile;
    vector<vector<Gate*>> pile_bis;


    g_queue.push(this);

    int i = g_queue.front()->getProfondeur()+1;
    sous_pile.push_back(g_queue.front());

    while(i>0){
        Gate* currentGate = g_queue.front();
        if (i>currentGate->getProfondeur()) {
            i=currentGate->getProfondeur();
            pile_bis.push_back(sous_pile);
            sous_pile.clear();
        }
        if (currentGate->getType()=="binary"){
             g_pile = currentGate->empileGates();
             g_pile.resize(g_pile.size()-1);
             break;
        }
        else{
            g_queue.push(((UnaryGate*)(currentGate))->getGate());
            sous_pile.push_back(g_queue.back());
        }
        g_queue.pop();
    }

    for( int i=pile_bis.size()-1;i>=0;i--)
    {
        g_pile.push_back(pile_bis[i]);
    }
    return g_pile;
}
