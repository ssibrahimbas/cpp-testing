//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include <list>
#include "internal/user/user.h"
#include "gtest/gtest.h"
#include "internal/table/Table.h"

namespace {
    std::list<User> createUsers() {
        std::list<User> users;
        users.emplace_back("John", 2340.32, 0.33, 3);
        users.emplace_back("Doe", 4330.32, 0.16, 1);
        users.emplace_back("Mark", 4700.32, 0.24, 4);
        return users;
    }

    User createUser(double price = 700.32) {
        User user("Doe John", price, 0.1, 7);
        return user;
    }

    TEST(TableClassTesting, tableInitialPriceTesting) {
        std::list<User> users = createUsers();
        Table table(users);
        EXPECT_EQ(0, table.price);
    }

    TEST(TableClassTesting, tableCalculateTotalPriceAndRichUserTesting) {
        std::list<User> users = createUsers();
        Table table(users);
        User richUser = table.calculateTotalPriceAndRichUser();
        EXPECT_EQ(4700.32, richUser.price);
        EXPECT_EQ(2340.32 + 4330.32 + 4700.32, table.totalPrice);
    }

    TEST(TableClassTesting, tableCheckUserEliminatedByPriceTesting) {
        std::list<User> users = createUsers();
        User user = createUser();
        users.push_back(user);
        Table table(users);
        table.checkUsersIsEliminated();
        EXPECT_EQ(table.users.size(), 3);
    }

    TEST(TableClassTesting, addPriceToTableTesting) {
        std::list<User> users = createUsers();
        User user = createUser();
        users.push_back(user);
        Table table(users);
        double price = 300;
        user.setPrice(user.price - price);
        table.addPriceToTable(price);
        EXPECT_EQ(300, table.price);
    }

    TEST(TableClassTesting, reducePriceToTableTesting) {
        std::list<User> users = createUsers();
        User user = createUser(2000);
        users.push_back(user);
        Table table(users);
        double price = 300;
        user.setPrice(user.price + price);
        table.reducePriceFromTable(price);
        EXPECT_EQ(0 - price,table.price);
    }

    TEST(TableClassTesting, totalPriceInGameTesting) {
        std::list<User> users = createUsers();
        User user = createUser(5000);
        users.push_back(user);
        Table table(users);
        double price = 300;
        user.setPrice(user.price + price);
        table.reducePriceFromTable(price);
        table.calculateTotalPriceAndRichUser();
        double totalPrice = 0;
        for(User user : users) {
            totalPrice = totalPrice + user.price;
        }
        EXPECT_EQ(totalPrice, table.totalPrice);
    }

    TEST(TableClassTesting, initalTableUsersIsEmptyTesting) {
        std::list<User> users = createUsers();
        Table table(users);
        EXPECT_FALSE(table.users.size() == 0);
    }

    TEST(TableClassTesting, userBalanceNotYetTesting) {
        std::list<User> users = createUsers();
        User user = createUser();
        users.push_back(user);
        Table table(users);
        table.checkUsersIsEliminated();
        EXPECT_EQ(3, table.users.size());
    }

}