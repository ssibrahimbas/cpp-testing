//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "user.h"

User::User(std::string _fullName, double _price, double _percentPerGame, int _favNumber) {
    this->fullName = std::move(_fullName);
    this->favNumber = _favNumber;
    this->percentPerGame = _percentPerGame;
    this->price = _price;
}

User::User() {}

double User::getPriceForRate() {
    return this->price * this->percentPerGame;
}

void User::setPrice(double _p) {
    this->price = _p;
}
