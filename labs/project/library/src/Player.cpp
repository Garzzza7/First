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

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}
