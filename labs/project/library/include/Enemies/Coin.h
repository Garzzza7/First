#ifndef OOPPROJECT_COIN_H
#define OOPPROJECT_COIN_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <ctime>


class Coin:public Enemy{
private:
int id{6};


public:
    Coin(Resource * base);
    ~Coin();
    int getID() override {return id;};
    void updatePhysics() override;
    void updateMovement() override;
    void move(const float dir_x, const float dir_y) override;
    //int getdmg() override;
};

#endif //OOPPROJECT_COIN_H
