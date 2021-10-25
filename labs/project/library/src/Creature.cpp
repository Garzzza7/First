//
// Created by Marcin Kwapisz on 2016-10-10.
//

#include "Human.h"
#include <iostream>
#include "Creature.h"
#include <math.h>

Creature::Creature(double x, double y, int strength) : posX{x}, posY{y}, strength{strength} {
    cout << "Constructor of Creature" << endl;
}

Creature::~Creature() {
    cout << "Destructor of Creature" << endl;
}

double Creature::getXPos() { return posX; }

double Creature::getYPos() { return posY; }

double Creature::distanceTo(Creature * creature) {
    double x = posX - creature->posX;
    double y = posY - creature->posY;
    return sqrt(x*x + y*y);

int Creature::getStrength() { return strength; }

void Creature::move(double dx, double dy) {
    posX += dx;
    posY += dy;
}

void Creature::print() {
    cout << posX << " " << posY << " " << strength << endl;
}
