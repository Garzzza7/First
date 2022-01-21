//
// Created by student on 1/19/22.
//

#include <iostream>
#include <Enemies/PPlant.h>

PPlant::PPlant(std::string id, int hp, int damage):Enemy(id,hp,damage,0) {
    if(!this->textureSheet.loadFromFile("/home/student/OOP/oop21_ww_06/labs/project/textures/pplant.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    this->pplant.setTexture(this->textureSheet);
}

PPlant::~PPlant() {

}

void PPlant::updatePhysics() {
    velocity.y += gravity/1000;
    this->pplant.move(velocity);
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
void PPlant::render(sf::RenderTarget &target) {
    target.draw(this->pplant);
}

void PPlant::update(sf::RenderTarget &target) {

    this->updatePhysics();
    this->updateMovement();
}