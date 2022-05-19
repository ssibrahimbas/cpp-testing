//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "GameEngine.h"


void GameEngine::finish() {
    this->printWinner();
}

void GameEngine::start() {
    this->nextTour();
    while(this->table.users.empty() == 0) {

        this->nextTour();
    }
    if(this->table.users.empty()) {
        this->finish();
    }
}

void GameEngine::print() {
    this->printer.printX50Star();
    this->printer.printCenterForX50AndFillSpace("LUCKY PERSON: " + std::to_string(this->luckNumber));
    this->printer.printX50Star();
    this->printer.printX50Star();
    this->printer.printCenterForX50AndFillSpace("TOUR: " + std::to_string(this->tour));
    this->printer.printCenterForX50AndFillSpace("TABLE BALANCE: " + std::to_string(this->table.price) + " ₺");
    this->printer.printCenterForX50AndFillSpace("");
    std::cout << this->printer.getStringX46AndFillHyphen(46) << std::endl;
    this->printer.printCenterForX50AndFillSpace("THE RICHEST PERSON");
    this->printer.printCenterForX50AndFillSpace("BALANCE: " + std::to_string(this->richUser.price) + " ₺");
    this->printer.printCenterForX50AndFillSpace(this->richUser.fullName);
    this->printer.printCenterForX50AndFillSpace("");
    this->printer.printX50Star();
}

int GameEngine::nextTour() {
    this->tour++;
    this->calculateLuckNumber();
    int isFinished = this->playTour();
    this->richUser = this->table.calculateTotalPriceAndRichUser();
    this->print();
    return isFinished;
}

void GameEngine::calculateLuckNumber() {
    this->luckNumber = Number::randomNumber(1, 10);
}

int GameEngine::playTour() {
    if(this->table.users.empty()) {
        this->finish();
        return 0;
    }
    for(auto &user : this->table.users) {
        if(user.favNumber == this->luckNumber) {
            double price = user.getPriceForRate() * 10;
            this->table.reducePriceFromTable(price);
            user.setPrice(user.price + price);
        }else {
            double price = user.getPriceForRate();
            user.setPrice(user.price - price);
            this->table.addPriceToTable(price);
        }
    }
    return 1;
}

void GameEngine::printWinner() {
    this->printer.printCenterForX50AndFillSpace("GAME FINISHED");
    this->printer.printCenterForX50AndFillSpace("");
    this->printer.printCenterForX50AndFillSpace("");
    this->printer.printCenterForX50AndFillSpace("");
    this->printer.printX50Star();
}

GameEngine::GameEngine(Table _t, IPrinter _p, int _env) {
    this->printer = _p;
    this->table = _t;
    this->luckNumber = 0;
    this->tour = 0;
    this->env = _env;
}

GameEngine::GameEngine() {
}
