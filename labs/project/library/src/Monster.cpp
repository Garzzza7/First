//
// Created by Marcin Kwapisz on 2016-10-07.
//
#include <iostream>

#include "Monster.h"
#include "functions.h"

using namespace std;

Monster::Monster(double x, double y, int strength) : Creature(x, y, strength) {
    cout << "Constructor of Monster" << endl;
}

Monster::~Monster() {
    cout << "Destructor of Monster" << endl;
}

void Monster::print() {
    cout << "Monster ";
    Creature::print();
}

void Monster::decision() {
    int n = 3;
    move(drawNumber(n), drawNumber(n));
}