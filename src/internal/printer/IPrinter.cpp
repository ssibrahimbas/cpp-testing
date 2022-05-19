//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "IPrinter.h"

void IPrinter::printX50Star() {
    if(this->env == 1) {
        std::cout << this->getStringByLength(50, "#") << std::endl;
    }
}

void IPrinter::printX46StarAndFillHyphen() {
    if(this->env == 1) {
        std::cout << this->getStringX46AndFillHyphen(46) << std::endl;
    }
}

void IPrinter::printCenterForX50AndFillSpace(std::string text) {
    if(this->env == 1) {
        std::string corner = "##";
        if(text.length() >= 46) {
            std::cout << text << std::endl;
        }else {
            std::cout << this->getStringCenteredAndFillSpace(46, text, " ") << std::endl;
        }
    }
}

IPrinter::IPrinter(int env) {
    this->env = env;
}

std::string IPrinter::getStringByLength(int length, std::string space) {
    std::string result;
    int index = 0;
    while (index < length) {
        ++index;
        result += space;
    }
    return result;
}

std::string IPrinter::getStringX46AndFillHyphen(int length) {
    std::string result;
    std::string corner = "##";
    int index = 0;
    result += corner;
    while (index < length) {
        ++index;
        result += "-";
    }
    result += corner;
    return result;
}

std::string IPrinter::getStringCenteredAndFillSpace(int length, std::string text, std::string space) {
    std::string result;
    std::string corner = "##";
    result += corner;
    int spaces = length - text.length();
    std::string _space_ = this->getStringByLength((spaces % 2 == 0 ? spaces / 2 : (spaces / 2) + 1), space);
    result += _space_;
    result += text;
    result += _space_;
    result += corner;
    return result;
}
