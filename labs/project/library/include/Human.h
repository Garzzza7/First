//
// Created by Marcin Kwapisz on 2016-10-07.
//

#ifndef OOPPROJECT_HUMAN_H
#define OOPPROJECT_HUMAN_H

#include <string>
#include "Creature.h"

using namespace std;

class Human : public Creature {

    std::string name;
public:

    Human(string name, double x, double y, int strength);

    string getName();
    void decision();
    void print();

    virtual ~Human();
};

#endif //OOPPROJECT_HUMAN_H

