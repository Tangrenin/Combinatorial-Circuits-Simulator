//
// Created by user on 20/12/2021.
//

#ifndef UNTITLED7_OUTPUTGATE_H
#define UNTITLED7_OUTPUTGATE_H

#include "Gate.h"
#include <string>
#include <vector>

class OutputGate {
private:
    std::vector<std::vector<Gate *>> g_pile;
    Gate *g_main;
    std::string g_main_text;
    char name;
    static char nameTracker;
public:
    explicit OutputGate(Gate *main);
    OutputGate(const OutputGate &o);
    explicit OutputGate(std::string mainText);
    ~OutputGate();
    // Getters
    Gate *getMainGate() const;
    std::string getMainText() const;
    std::vector<std::vector<Gate *>> getPile() const;
    char getName() const;
    // Class Methods
    void showOutput() const;
    void outputToText() const;
    int calculerOutput() const;
    void saveInFile() const;
    static Gate *generateByExpr(std::string expr);
    static std::pair<std::string, std::string> parseExprIntoArgs(std::string expr);
};


#endif //UNTITLED7_OUTPUTGATE_H
