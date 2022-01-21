//
// Created by student on 1/21/22.
//

#ifndef OOPPROJECT_PPLANT_H
#define OOPPROJECT_PPLANT_H

#include "Enemy.h"

class PPlant: public Enemy {

    sf::Sprite pplant;
public:
    PPlant(ObjectBase * base, int hp, int damage);
    ~PPlant();

    //  void updatePhysics();
    //void updateMovement();
    //void move(const float dir_x, const float dir_y) override;

    //sf::Event lol;
    //Update functions run every frame.
    void update() override;
    void updatePhysics() override ;
    void updateMovement() override;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    void move(const float dir_x, const float dir_y) override;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    //void checkCollisions(sf::RenderTarget & target);

};

#endif //OOPPROJECT_PPLANT_H
