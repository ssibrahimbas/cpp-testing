//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#ifndef TESTING_FSHELPER_H
#define TESTING_FSHELPER_H

#include <string>
#include "../user/user.h"
#include<list>

class FsHelper {
public:
    std::list<User> getUsers(const std::string& fileName);
    void setFile(const std::string& fileName, const std::string& text);
};


#endif //TESTING_FSHELPER_H
