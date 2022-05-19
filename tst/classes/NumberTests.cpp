//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "gtest/gtest.h"
#include "internal/number/Number.h"

namespace {
    TEST(NumberClassTest, randomNumberIsRandomReallyTest) {
        int numberOne = Number::randomNumber(1,10);
        int numberTwo = Number::randomNumber(1,10);
        EXPECT_TRUE(numberOne != numberTwo);
    }

    TEST(NumberClassTest, randomNumberIsItRangeTest) {
        int min = 1;
        int max = 10;
        int randNumber = Number::randomNumber(min, max);
        EXPECT_TRUE(randNumber >= min);
        EXPECT_TRUE(randNumber <= max);
    }

    TEST(NumberClassTest, doesTheRandomOfRandomExceedTheMaxTesting) {
        int min = 1, max = 10, index = 0;
        while(index < 100000) {
            ++index;
            int randNumber = Number::randomNumber(min, max);
            EXPECT_TRUE(randNumber <= max);
        }
    }

    TEST(NumberClasstest, doesTheRandomOfRandomExceedTheMinTesting) {
        int min = 1, max = 10, index = 0;
        while(index < 100000) {
            ++index;
            int randNumber = Number::randomNumber(min, max);
            EXPECT_TRUE(randNumber >= min);
        }
    }
}