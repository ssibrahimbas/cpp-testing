//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#ifndef TESTING_USER_H
#define TESTING_USER_H

#include <utility>

#include "string"


class User {
public:
    std::string fullName;
    double price;
    double percentPerGame;
    int favNumber;

    User(std::string _fullName, double _price, double _percentPerGame, int _favNumber);

    double getPriceForRate();
    void setPrice(double _p);
    bool operator == (const User& u) const { return fullName == u.fullName; }
    bool operator != (const User& u) const { return !operator==(u); }

    User();

};


#endif //TESTING_USER_H
