#include <iostream>
#include "Enemies/Enemy.h"
#include "Tiles/ObjectRegistry.h"


Enemy::Enemy(ObjectBase * base,int hp,int damage,float acceleration) {
    this->base = base;
    this->hp = hp;
    this->damage = damage;
    this->acceleration = acceleration;
}
Enemy::~Enemy() {

}

void Enemy::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}

void Enemy::update() {
    this->updatePhysics();
    this->updateMovement();
}

void Enemy::updatePhysics() {
    velocity.y += gravity/1000;
    //this->goomba.move(velocity);
}
void Enemy::updateMovement() {}

void Enemy::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::setPosition(sf::Vector2f position) {
    this->sprite.setPosition(position);
}

void Enemy::setTilePosition(float x, float y) {
    ObjectRegistry * objectRegistry = ObjectRegistry::GetInstance();
    this->sprite.setPosition(x * objectRegistry->getTileSize(), y * objectRegistry->getTileSize());
}
