//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "Table.h"

#include <utility>

void Table::addPriceToTable(double &_price) {
    this->price = this->price + _price;
}

void Table::reducePriceFromTable(double &_price) {
    this->price = this->price - _price;
}

User Table::calculateTotalPriceAndRichUser() {
    User richUser;
    int index = -1;
    double _totalPrice = 0;
    for(auto &user : this->users) {
        index++;
        _totalPrice = _totalPrice + user.price;
        if(index == 0) {
            richUser = user;
            continue;
        }
        if(user.price > richUser.price) {
            richUser = user;
        }
    }
    this->checkUsersIsEliminated();
    this->totalPrice = _totalPrice;
    return richUser;
}

void Table::checkUsersIsEliminated() {
    std::list<User>::iterator it = this->users.begin();
    while (it != this->users.end()) {
        if(it->price < 1000) {
            it = this->users.erase(it);
        }else {
            ++it;
        }
    }
}

Table::Table(std::list<User> _users) {
    this->users = std::move(_users);
    this->price = 0;
    this->totalPrice = 0;
    this->calculateTotalPriceAndRichUser();
}

Table::Table() {

}
