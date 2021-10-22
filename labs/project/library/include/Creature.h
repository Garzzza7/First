//
// Created by Marcin Kwapisz on 2016-10-10.
//

#ifndef OOPPROJECT_CREATURE_H
#define OOPPROJECT_CREATURE_H

class Creature {
    double posX;
    double posY;
    int strength;

protected:
    void move(double dx, double dy);

public:

    Creature(double, double, int);

    double getXPos();

    double getYPos();

    int getStrength();

    void print();

    virtual ~Creature();
};


#endif //OOPPROJECT_CREATURE_H
