//
// Created by Marcin Kwapisz on 2016-10-07.
//

#ifndef OOPPROJECT_WORLD_H
#define OOPPROJECT_WORLD_H

class Human;
class Monster;

class World {
private:
    Human* human1;
    Human* human2;
    Monster *monster;
public:
    World();
    virtual ~World();

    void startSimulation(int n);
};


#endif //OOPPROJECT_WORLD_H
