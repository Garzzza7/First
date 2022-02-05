#ifndef OOPPROJECT_PLAYER_H
#define OOPPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Resources/ResourceRegistry.h"
#include "AnimatedGif.h"
#include "Level.h"
#include "Enemies/Enemy.h"

class Player{

    sf::FloatRect nextPos;
    sf::Sprite sprite;
    sf::FloatRect collisionRect;

    sf::Texture standingTexture;
    sf::Texture jumpingTexture;
    AnimatedGif gif;

    int x;
    int y;

    bool goingRight{false};
    bool goingLeft{false};
    bool goingToJump{false};

   unsigned int playerHealth{5};

    bool onGround{false};
    unsigned jumpCount{0};

    //Private methods:

    void move(float dir_x);
    void jump(float dir_x, float dir_y);

    void setPositionX(float x);
    void setPositionY(float y);

    void changeToStandingTexture();
    void changeToJumpingTexture(bool moveDirection);
    void changeToGif(bool moveDirection);

    void setOnGround(bool onGround);

    //Physics:
    sf::Vector2f velocity{0,0};
    float gravity{10.f};
    float acceleration{0.2f};
    float maxVelocity{3.0f};
    float friction{0.5f};

public:

    Player(int x , int y);
    ~Player();

    //Render works like update but is run before update:
    void render(sf::RenderTarget & target);

    //Catching events before update:
    void catchEvents(sf::Event event);

    //Update functions run every frame.
    void update(sf::RenderTarget & target);
    void updatePhysics();
    void updateMovement();
    void updateAnimations();

    //Getters:
    sf::FloatRect getPlayerBounds();
    sf::Vector2f getPos() {return sprite.getPosition();};
    int getHP();

    //Collisions:
    void checkCollisions();
    void enemyCollisions();

    //Player health functions:
    void receiveDamage(unsigned int& hp);
    void die();

};

#endif //OOPPROJECT_PLAYER_H
