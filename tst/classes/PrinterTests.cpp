//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//
#include "gtest/gtest.h"
#include "internal/printer/IPrinter.h"

namespace {
    TEST(PrinterClassTest, printerGetStringByLengthTesting) {
        IPrinter printer;
        std::string str = printer.getStringByLength(50, "*");
        EXPECT_EQ(str, "**************************************************");
    }

    TEST(PrinterClassTest, printerGetStringX46AndFillHyphenTesting) {
        IPrinter printer;
        std::string str = printer.getStringX46AndFillHyphen(46);
        EXPECT_EQ(str, "##----------------------------------------------##");
    }

    TEST(PrinterClassTest, printerGetCenteredAndFillSpaceTesting) {
        IPrinter printer;
        std::string str = printer.getStringCenteredAndFillSpace(46, "Hello world!", " ");
        std::cout << str << std::endl;
        EXPECT_EQ(str, "##                 Hello world!                 ##");
    }

    TEST(PrinterClassTest, printerGetCenteredWithInOddNumbersTesting) {
        IPrinter printer;
        std::string str = printer.getStringCenteredAndFillSpace(45, "Hello world!", " ");
        std::cout << str << std::endl;
        EXPECT_EQ(str, "##                 Hello world!                 ##");
    }}