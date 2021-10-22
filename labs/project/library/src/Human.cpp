//
// Created by Marcin Kwapisz on 2016-10-07.
//
#include <iostream>

#include "Human.h"
#include "functions.h"

using namespace std;

Human::Human(string name, double posX, double posY, int strength) : name(name), Creature(posX, posY, strength) {
    cout << "Constructor of Human " << name << endl;
}

Human::~Human() {
    cout << "Destructor of Human " << name << endl;
}

void Human::print() {
    cout << name << " ";
    Creature::print();
}

void Human::decision() {
    int n = 5;
    move(drawNumber(n), drawNumber(n));
}

string Human::getName() {
    return name;
}