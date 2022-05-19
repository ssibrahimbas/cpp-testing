//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//
#include "gtest/gtest.h"
#include "internal/user/user.h"

namespace {
    TEST(UserClassTesting, priceInitialTesting) {
        User user;
        EXPECT_EQ(0, user.price);
    }
    TEST(UserClassTesting, fullNameInitialTesting) {
        User user;
        EXPECT_EQ("", user.fullName);
    }
    TEST(UserClassTesting, percentPerGameInitialTesting) {
        User user("John", 0,0,0);
        EXPECT_EQ(0, user.percentPerGame);
    }
    TEST(UserClassTesting, userFavNumberTesting) {
        User user("John Doe", 23, 22, 3);
        EXPECT_EQ(3, user.favNumber);
    }
    TEST(UserClassTesting, userPriceForRateTesting) {
        double price = 3050.33;
        double percentPerGame = 0.33;
        User user("John Doe", price, percentPerGame, 3);
        EXPECT_EQ(price * percentPerGame, user.getPriceForRate());
    }
    TEST(UserClassTesting, userSetPriceTesting) {
        double firstPrice = 3050.33;
        double lastPrice = 7041.32;
        User user("John Doe", firstPrice, 0.33, 3);
        user.setPrice(lastPrice);
        EXPECT_EQ(lastPrice, user.price);
    }
    TEST(UserClassTesting, userFullNameTesting) {
        std::string fullName = "John Doe";
        User user(fullName, 3402.2, 0.3, 3);
        EXPECT_EQ(fullName, user.fullName);
    }
}