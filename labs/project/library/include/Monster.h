//
// Created by Marcin Kwapisz on 2016-10-07.
//

#ifndef OOPPROJECT_MONSTER_H
#define OOPPROJECT_MONSTER_H

#include "Creature.h"

class Monster : public Creature{

public:
    Monster(double x, double y, int strength);

    void decision();
    void print();

    virtual ~Monster();

};

#endif //OOPPROJECT_MONSTER_H

