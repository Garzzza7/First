//
// Created by student on 1/19/22.
//

#include <iostream>
#include <Enemies/Goomba.h>

Goomba::Goomba(std::string id, int hp, int damage, float acceleration):Enemy(id,hp,damage,acceleration) {
    if(!this->textureSheet.loadFromFile("/home/student/OOP/oop21_ww_06/labs/project/textures/gooomba.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    this->goomba.setTexture(this->textureSheet);
}

Goomba::~Goomba() {

}

void Goomba::updatePhysics() {
    velocity.y += gravity/1000;
    this->goomba.move(velocity);
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
void Goomba::render(sf::RenderTarget &target) {
  target.draw(this->goomba);
}

void Goomba::update(sf::RenderTarget &target) {

    this->updatePhysics();
    this->updateMovement();
}