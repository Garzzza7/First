//
// Created by student on 1/21/22.
//

#ifndef OOPPROJECT_PPLANT_H
#define OOPPROJECT_PPLANT_H

#include "Entity.h"
#include "Strategies/StrategyDamagePlayer.h"

class PPlant : public Entity {
    int id{5};
    int hp{2};
    int damage{2};
    float acceleration{0};

    sf::Sprite pplant;
public:
    PPlant(Resource * base);
    ~PPlant();

    void updatePhysics() override;
    void updateMovement() override;

    void move(float dir_x, float dir_y) override;

};

#endif //OOPPROJECT_PPLANT_H
