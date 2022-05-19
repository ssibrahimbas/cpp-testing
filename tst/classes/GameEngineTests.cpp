//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//
#include <list>
#include "gtest/gtest.h"
#include "internal/user/user.h"
#include "internal/table/Table.h"
#include "internal/engine/GameEngine.h"

namespace {
    std::list<User> createUsers() {
        std::list<User> users;
        users.emplace_back("John", 2340.32, 0.33, 3);
        users.emplace_back("Doe", 4330.32, 0.16, 1);
        users.emplace_back("Mark", 4700.32, 0.24, 4);
        return users;
    }

    User createUser(double price = 2350) {
        User user("Doe John", price, 0.1, 7);
        return user;
    }

    Table createTable() {
        std::list<User> users = createUsers();
        Table table(users);
        return table;
    }

    IPrinter createPrinter() {
        IPrinter printer(0);
        return printer;
    }

    TEST(GameEngineTesting, gameEngineInitLuckNumberTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        EXPECT_EQ(0, engine.luckNumber);
    }

    TEST(GameEngineTesting, gameEngineInitTourTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        EXPECT_EQ(0, engine.tour);
    }

    TEST(GameEngineTesting, gameEngineTourSuccessfullyRunningTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        EXPECT_EQ(0, engine.tour);
        engine.nextTour();
        engine.nextTour();
        engine.nextTour();
        EXPECT_EQ(3, engine.tour);
    }

    TEST(GameEngineTesting, gameEngineLuckNumberIsReallyRandomTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.nextTour();
        int luck = engine.luckNumber;
        engine.nextTour();
        EXPECT_TRUE(engine.luckNumber != luck);
    }

    TEST(GameEngineTesting, gameEngineInitialRichUserTesting) {
        std::list<User> users = createUsers();
        User user = createUser(5000000);
        users.push_back(user);
        Table table(users);
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.nextTour();
        EXPECT_EQ(user.fullName, engine.richUser.fullName);
    }

    TEST(GameEngineTesting, gameEnginePlayAndTourTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.start();
        EXPECT_TRUE(engine.tour > 0);
    }

    TEST(GameEngineTesting, gameEnginePlayAndLuckNumberTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.start();
        EXPECT_TRUE(engine.luckNumber > 0);
    }

    TEST(GameEngineTesting, gameEnginePlayAndThereAreNoUserTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.start();
        EXPECT_TRUE(engine.table.users.size() == 0);
    }

    TEST(GameEngineTesting, gameEngineRichUserPriceAndPrintTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.nextTour();
        std::string balanceText = engine.printer.getStringCenteredAndFillSpace(46, "BALANCE : " + std::to_string(engine.richUser.price) + " ₺");
        EXPECT_EQ(balanceText, "##           BALANCE : 3637.468800 ₺           ##");
    }

    TEST(GameEngineTesting, gameEngineRichUserNameAndPrintTesting) {
        Table table = createTable();
        IPrinter printer = createPrinter();
        GameEngine engine(table, printer, 0);
        engine.nextTour();
        std::string text = engine.printer.getStringCenteredAndFillSpace(46, engine.richUser.fullName);
        EXPECT_EQ(text, "##                     Mark                     ##");
    }


}