//
// Created by student on 12/16/21.
//
#include <iostream>
#include "Player.h"

Player::Player(float x , float y) {
    this->sprite.setPosition(x,y);
    this->sprite.setOrigin(40.f,40.f);
   // this->sprite.

    if(!this->textureSheet.loadFromFile("/home/student/OOP/oop21_ww_06/labs/project/textures/player.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    this->sprite.setTexture(this->textureSheet);
   // this->sprite.setPosition(100.f,100.f);
}

Player::~Player() {

}

void Player::move(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    if (std::abs(this->velocity.x) > this->maxVelocity) {
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
 //   if (event.type == sf::Event::KeyReleased) {
   //     if (event.key.code == sf::Keyboard::Key::D || event.key.code == sf::Keyboard::Key::A) {
     //       this->velocity.x = 0;
       // }
    //}
}
void Player::jump(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    this->velocity.y +=dir_y * gravity;
    if(std::abs(this->velocity.x) > this->maxVelocity){
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
    if(std::abs(this->velocity.y) > this->maxVelocity){
        this->velocity.y = this->maxVelocity * ((this->velocity.y < 0.f) ? -1.f : 1.f);
    }
}
void Player::stop(const float dir_x, const float dir_y) {
    //this->velocity.x -= dir_x * acceleration;
    for(int i=0; i<3 ; i++)
    {
        this->velocity.x -= dir_x * i *acceleration;
    }
}






void Player::update(sf::RenderTarget & target){

    this->updatePhysics();
    this->updateMovement();
    this->windowBounds(target);
}

void Player::updatePhysics() {

    velocity.y += gravity/1000;
    this->sprite.move(velocity);
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        if(!this->textureSheet.loadFromFile("/home/student/OOP/oop21_ww_06/labs/project/textures/marioLeft.png")){
            std::cout << "ERROR: Could not load texture" << "\n";
        }
        this->sprite.setTexture(this->textureSheet);
        this->move(-1,0);
      //  this->stop(-1,0);
    }
  // else this->velocity.x=0;;



    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        if(!this->textureSheet.loadFromFile("/home/student/OOP/oop21_ww_06/labs/project/textures/player.png")){
            std::cout << "ERROR: Could not load texture" << "\n";
        }
        this->sprite.setTexture(this->textureSheet);
        this->move(1,0);
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->velocity.x=0;;
    }



    /*
    if(event.type==sf::Event::KeyReleased)
    {
      if(event.key.code==sf::Keyboard::Key::D || event.key.code==sf::Keyboard::Key::A)
        {
            this->stop(this->velocity.x,0);
        }

    }
*/
    //if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Key::A)
    //{
    //    this->velocity.x=0;
    //}


    if(sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::W)){
            this->jump(0,-1);

        }



  // else if
}

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}


void Player::windowBounds(sf::RenderTarget & target) {

    if(this->sprite.getGlobalBounds().left <=0.f) this->sprite.setPosition(0.f , this->sprite.getPosition().y);
    else if(this->sprite.getGlobalBounds().left+this->sprite.getGlobalBounds().width>=target.getSize().x) this->sprite.setPosition(target.getSize().x - this->sprite.getGlobalBounds().width,this->sprite.getGlobalBounds().top);

    if(this->sprite.getGlobalBounds().top+this->sprite.getGlobalBounds().height >= target.getSize().y /*-100.f*/) this->sprite.setPosition(this->sprite.getGlobalBounds().left, target.getSize().y - this->sprite.getGlobalBounds().height  /*-100.f*/);
}