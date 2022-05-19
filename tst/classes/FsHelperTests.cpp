//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "string"
#include "gtest/gtest.h"
#include "internal/fs/fsHelper.h"

namespace {
    std::string getFileString() {
        return "Keeleigh Millhouse#12345.23#0.54#2\n"
               "Starr Sinclair#98765.14#0.42#7\n"
               "Chloe Neil#88641.45#0.34#5\n";
    }

    std::list<User> setAndGetUsersFromFile() {
        std::string text = getFileString();
        FsHelper fsHelper;
        fsHelper.setFile("users", text);
        std::list<User> users = fsHelper.getUsers("users");
        return users;
    }

    TEST(FsUnitTest, fsIsParseUsersTesting) {
        std::list<User> users = setAndGetUsersFromFile();
        EXPECT_FALSE(users.empty());
    }

    TEST(FsUnitTest, fsParseUsersCountTesting) {
        std::list<User> users = setAndGetUsersFromFile();
        EXPECT_EQ(3, users.size());
    }

    TEST(FsUnitTest, fsParseUsersIsSuccessTesting) {
        std::list<User> users = setAndGetUsersFromFile();
        for(User user : users) {
            EXPECT_FALSE(user.price == 0);
            EXPECT_FALSE(user.fullName == "");
            EXPECT_FALSE(user.percentPerGame == 0);
            EXPECT_FALSE(user.favNumber == 0);
        }
    }


}