//
// Created by user on 20/12/2021.
//

#include "UnaryGate.h"

Gate* UnaryGate::getGate(){
    return g_main;
}

UnaryGate::UnaryGate(Gate* main): g_main(main){}
