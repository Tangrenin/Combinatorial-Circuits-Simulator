cmake_minimum_required(VERSION 3.20)
project(untitled7)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled7 main.cpp OutputGate.cpp OutputGate.h InputGate.cpp InputGate.h Gate.cpp Gate.h BinaryGate.cpp BinaryGate.h UnaryGate.cpp UnaryGate.h AndGate.cpp AndGate.h OrGate.cpp OrGate.h XorGate.cpp XorGate.h)
