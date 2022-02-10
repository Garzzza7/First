#ifndef OOPPROJECT_COIN_H
#define OOPPROJECT_COIN_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Entities/Strategies/StrategyChangeLevel.h"
#include <ctime>


class Coin : public Entity{
private:
    int id{6};

public:
    Coin(Resource * base);
    ~Coin();
    int getID() override {return id;};
    void updatePhysics() override;
    void updateMovement() override;
    void move(const float dir_x, const float dir_y) override;
    //int getDamage() override;
};

#endif //OOPPROJECT_COIN_H
