//
// Created by Marcin Kwapisz on 2016-10-07.
//
#include "World.h"
#include "Human.h"
#include "Monster.h"

#include<iostream>

using namespace std;

World::World() {
    cout << "Constructor of World" << endl;
    human1 = new Human("Adam", 2, 2, 3);
    human2 = new Human("Eve", 3, 4, 5);
    monster = new Monster(0, 2, 4);
}

World::~World() {
    cout << "Destructor of World" << endl;
    delete human1;
    delete human2;
    delete monster;

}

void World::startSimulation(int n) {
    human1->print();
    human2->print();
    monster->print();
    for (int i = 0; i < n; i++) {
        human1->decision();
        human2->decision();
        monster->decision();
        human1->print();
        human2->print();
        monster->print();
    }
}
