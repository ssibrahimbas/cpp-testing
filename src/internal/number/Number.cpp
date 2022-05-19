//
// Created by Sami Salih İbrahimbaş on 8.05.2022.
//

#include <cstdlib>
#include "Number.h"

int Number::randomNumber(const int &min, const int &max) {
    return rand() % (max - min + 1) + min;
}
