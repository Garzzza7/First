//
// Created by student on 12/16/21.
//
#include <iostream>
#include "Player.h"

Player::Player() {

    if(!this->textureSheet.loadFromFile("../../textures/player.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    this->sprite.setTexture(this->textureSheet);
}

Player::~Player() {

}

void Player::move(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    if(abs(this->velocity.x) > this->maxVelocity){
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
}

void Player::update(){
    this->updatePhysics();
    this->updateMovement();
}

void Player::updatePhysics() {

    velocity.y += gravity/1000;
    this->sprite.move(velocity);
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) this->move(-1,0);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) this->move(1,0);
}

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}
