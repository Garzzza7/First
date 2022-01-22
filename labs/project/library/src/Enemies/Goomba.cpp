//
// Created by student on 1/19/22.
//

#include <iostream>
#include "Enemies/Goomba.h"

Goomba::Goomba(ObjectBase * base, int hp, int damage, float acceleration) : Enemy(base, hp, damage, acceleration) {

}

Goomba::~Goomba() {
    std::cout << "This@!";
}



void Goomba::updatePhysics() {
    velocity.y += gravity/100;
    this->sprite.move(velocity);
}
void Goomba::updateMovement() {

    srand((unsigned) time(0));
    int randomNumber=1 + (rand() % 6);;
    if(randomNumber%2==0)
    {
        this->move(-1,0);
    } else this->move(1,0);

}
void Goomba::move(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    if (std::abs(this->velocity.x) > this->maxVelocity) {
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);

    }
}

void Goomba::update() {

    this->updatePhysics();
    this->updateMovement();
}