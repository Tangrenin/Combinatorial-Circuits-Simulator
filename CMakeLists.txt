cmake_minimum_required(VERSION 3.20)
project(untitled7)

set(CMAKE_CXX_STANDARD 11)

add_executable(untitled7 main.cpp Gates/OutputGate.cpp Gates/OutputGate.h Gates/InputGate.cpp Gates/InputGate.h Gates/Gate.cpp Gates/Gate.h Gates/BinaryGate.cpp Gates/BinaryGate.h Gates/UnaryGate.cpp Gates/UnaryGate.h Gates/BinaryGates/AndGate.cpp Gates/BinaryGates/AndGate.h Gates/BinaryGates/OrGate.cpp Gates/BinaryGates/OrGate.h Gates/BinaryGates/XorGate.cpp Gates/BinaryGates/XorGate.h Gates/BinaryGates/NandGate.cpp Gates/BinaryGates/NandGate.h Gates/BinaryGates/NorGate.cpp Gates/BinaryGates/NorGate.h Gates/UnaryGates/NegateGate.cpp Gates/UnaryGates/NegateGate.h Gates/BinaryGates/NxorGate.cpp Gates/BinaryGates/NxorGate.h)
