//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#ifndef Testing_GAMEENGINE_H
#define Testing_GAMEENGINE_H

#include "../table/Table.h"
#include "../number/Number.h"
#include "string"
#include "../printer/IPrinter.h"

class GameEngine {
public:
    Table table;
    User richUser;
    IPrinter printer;
    int luckNumber;
    int tour;

    void print();
    void printWinner();
    void start();
    void finish();
    int nextTour();

    GameEngine();
    explicit GameEngine(Table _t, IPrinter _p, int _env = 1);

private:
    void calculateLuckNumber();
    int playTour();
    int env;
};


#endif //Testing_GAMEENGINE_H
