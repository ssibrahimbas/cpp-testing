//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#ifndef TESTING_IPRINTER_H
#define TESTING_IPRINTER_H
#include "string"
#include "iostream"

class IPrinter {
public:
    int env;
    void printX50Star();
    void printX46StarAndFillHyphen();
    void printCenterForX50AndFillSpace(std::string text);
    std::string getStringByLength(int length = 10, std::string space = " ");
    std::string getStringX46AndFillHyphen(int length = 10);
    std::string getStringCenteredAndFillSpace(int length, std::string text, std::string space = " ");

    explicit IPrinter(int env = 1);
};


#endif //TESTING_IPRINTER_H
