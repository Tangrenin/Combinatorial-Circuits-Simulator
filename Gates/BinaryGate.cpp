//
// Created by user on 20/12/2021.
//

#include "BinaryGate.h"

Gate* BinaryGate::getGateRight() const {
    return g_right;
}

Gate* BinaryGate::getGateLeft() const {
    return g_left;
}

BinaryGate::BinaryGate(Gate* left, Gate* right): g_left(left), g_right(right){}


