//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#ifndef TESTING_TABLE_H
#define TESTING_TABLE_H

#include "list"
#include "string"
#include "../user/user.h"

class Table {
public:
    std::list<User> users;
    double price;
    double totalPrice;

    User calculateTotalPriceAndRichUser();
    void addPriceToTable(double& _price);
    void reducePriceFromTable(double& _price);
    void checkUsersIsEliminated();

    Table();
    Table(std::list<User> _users);
};


#endif //TESTING_TABLE_H
