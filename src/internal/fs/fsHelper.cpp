//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include "fsHelper.h"
#include <fstream>
#include <string>
#include <sstream>

std::list<User> FsHelper::getUsers(const std::string &fileName) {
    std::string extension = ".txt";
    std::list<User> users;

    std::ifstream file(fileName + extension);
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string symbol;
        std::string numstr;

        std::getline(ss, symbol, '#');
        std::getline(ss, numstr, '#');
        double price = std::stod(numstr);
        std::getline(ss, numstr, '#');
        double percentPerGame = std::stod(numstr);
        std::getline(ss, numstr, '#');
        int favNumber = std::stoi(numstr);

        users.push_back(User(symbol, price, percentPerGame, favNumber));
    }

    file.close();

    return users;
}

void FsHelper::setFile(const std::string &fileName, const std::string &text) {
    std::string extension = ".txt";
    std::ofstream file;
    file.open(fileName + extension);
    file << text;
    file.close();
}
