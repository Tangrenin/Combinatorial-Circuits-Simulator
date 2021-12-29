//
// Created by user on 20/12/2021.
//

#include "BinaryGate.h"
#include "UnaryGate.h"
#include <queue>
#include "iostream"

using namespace std;

Gate* BinaryGate::getGateRight() const {
    return g_right;
}

Gate* BinaryGate::getGateLeft() const {
    return g_left;
}

BinaryGate::BinaryGate(Gate* left, Gate* right): g_left(left), g_right(right){}

std::string BinaryGate::getType() const{
    return "binary";
}

int BinaryGate::getProfondeur() const {
    return std::max(g_right->getProfondeur(), g_left->getProfondeur())+1;
}


std::vector<std::vector<Gate *>> BinaryGate::empileGates() {

    vector<vector<Gate*>> g_pile, pile_bis;
    queue<Gate *> g_queue;
    vector<Gate*> sous_pile;


    g_queue.push(this);

    int i = g_queue.front()->getProfondeur();
    sous_pile.push_back(g_queue.front());
    pile_bis.push_back(sous_pile);
    sous_pile.clear();

    Gate* currentGate = g_queue.front();

    while(i>0){

        if (currentGate->getType()=="binary"){
            if((((BinaryGate*)(currentGate))->getGateRight()->getProfondeur())>(((BinaryGate*)(currentGate))->getGateLeft()->getProfondeur())){
                g_queue.push(((BinaryGate*)(currentGate))->getGateRight());
                sous_pile.push_back(g_queue.back());
                g_queue.push(((BinaryGate*)(currentGate))->getGateLeft());
                sous_pile.push_back(g_queue.back());
            }else{
                g_queue.push(((BinaryGate*)(currentGate))->getGateLeft());
                sous_pile.push_back(g_queue.back());
                g_queue.push(((BinaryGate*)(currentGate))->getGateRight());
                sous_pile.push_back(g_queue.back());
            }
        }
        else{
            g_queue.push(((UnaryGate*)(currentGate))->getGate());
            sous_pile.push_back(g_queue.back());
        }

        do  {
            g_queue.pop();
            currentGate = g_queue.front();
        }while(currentGate->getProfondeur() == 0 && (g_queue.size()>1));

        if (i!=currentGate->getProfondeur()){
            i=currentGate->getProfondeur();
            pile_bis.push_back(sous_pile);
            sous_pile.clear();
        }
    }

    for( int i=pile_bis.size()-1;i>=0;i--)
    {
        g_pile.push_back(pile_bis[i]);
    }
    return g_pile;
}

void BinaryGate::showLigne() {
    cout << " | ";
}


