//
// Created by Marcin Kwapisz on 2015-12-30.
//

#include <stdlib.h>

#include "functions.h"

double drawNumber(int n) {
    return rand() % (2 * n + 1) - n;
}