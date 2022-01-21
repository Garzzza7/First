#include <iostream>
#include <Enemies/Enemy.h>


Enemy::Enemy(std::string id,int hp,int damage,float acceleration) {
    this->id=id;
    this->hp=hp;
    this->damage=damage;
    this->acceleration=acceleration;
}
Enemy::~Enemy() {

}
void Enemy::update(sf::RenderTarget &target) {
    this->updatePhysics();
    this->updateMovement();
}
void Enemy::updatePhysics() {
    velocity.y += gravity/1000;
    //this->goomba.move(velocity);
}
void Enemy::updateMovement() {}