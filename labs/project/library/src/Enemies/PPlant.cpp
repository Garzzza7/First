//
// Created by student on 1/19/22.
//

#include <iostream>
#include "Enemies/PPlant.h"

PPlant::PPlant(ObjectBase * base, int hp, int damage) : Enemy(base, hp, damage,0) {

    this->sprite.setTexture(Enemy::getBase()->texture);
}

PPlant::~PPlant() {

}

void PPlant::updatePhysics() {
    velocity.y += gravity/1000;
    this->sprite.move(velocity);
}
void PPlant::updateMovement() {

    srand((unsigned) time(0));
    int randomNumber=1 + (rand() % 6);;
    if(randomNumber%2==0)
    {
        this->move(-1,0);
    } else this->move(1,0);

}
void PPlant::move(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    if (std::abs(this->velocity.x) > this->maxVelocity) {
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);

    }
}

void PPlant::update() {

    this->updatePhysics();
    this->updateMovement();
}