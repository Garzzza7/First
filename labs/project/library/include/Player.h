#ifndef OOPPROJECT_PLAYER_H
#define OOPPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "Resources/ResourceRegistry.h"
#include "AnimatedGif.h"
#include "Level.h"
#include "Entities/Entity.h"
//template<class T>
class Player{

    sf::Sprite sprite;
    sf::FloatRect collisionRect;

    sf::Texture standingTexture;
    sf::Texture jumpingTexture;
    AnimatedGif gif;

    int spawnPointPosX;
    int spawnPointPosY;

    bool goingRight{false};
    bool goingLeft{false};
    bool goingToJump{false};

    unsigned int playerHealth{5};

    bool onGround{false};
    unsigned jumpCount{0};

    //Private methods:

    void move(float dir_x);
    void jump();

    void setPositionX(float x);
    void setPositionY(float y);

    void changeToStandingTexture();
    void changeToJumpingTexture(bool moveDirection);
    void changeToGif(bool moveDirection);

    void setOnGround(bool onGround);

    void receiveDamage(unsigned int &hp,int dmg);
    void checkIfPlayerShouldDie();

    //Physics:
    sf::Vector2f velocity{0,0};
    float gravity{10.f};
    float acceleration{0.2f};
    float maxVelocity{3.0f};
    float friction{0.5f};

    bool isTourched{false};

public:

    Player(int x , int y);

    //Render works like update but is run before update:
    void render(sf::RenderTarget & target);

    //Catching events before update:
    void catchEvents(sf::Event event);

    bool CoinTouched(){return isTourched;};

    //Update functions run every frame.
    void update(sf::RenderTarget & target);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();
    void updateFallDamage();

    //Getters:
    sf::FloatRect getPlayerBounds() {return this->sprite.getGlobalBounds();};
    sf::Vector2f getPos() {return sprite.getPosition();};
     unsigned int getHP()  {return playerHealth;};

    //Collisions:
    sf::Vector2f getCollisionIntersection(sf::FloatRect nextPos);
    void checkCollisions();
    void enemyCollisions();

};

#endif //OOPPROJECT_PLAYER_H
