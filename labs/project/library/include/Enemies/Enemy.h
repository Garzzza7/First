#ifndef OOPPROJECT_ENEMY_H
#define OOPPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>

#include "Resources/ResourceRegistry.h"
#include "Resources/Resource.h"
#include "Tiles/Tile.h"

class Enemy{

    Resource * base;

    int hp;
    int damage;


    void setPositionX(float x);
    void setPositionY(float y);

protected:
    //Physics:
    sf::Vector2f velocity{0,0};
    float maxVelocity{2.0f};
    float acceleration{0.2f};
    float gravity{10.f};

    sf::Sprite sprite;

    bool flipMovement{false};

public:
    Enemy(Resource * base, int hp, int damage, float acceleration);
    //sf::Event lol;
    //Update functions run every frame.
    virtual void update();
    virtual void updatePhysics()=0;
    virtual void updateMovement()=0;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    virtual void move(const float dir_x, const float dir_y)=0;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

    void checkCollisions(Tile **tiles, int levelWidth, int levelLength);

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);

    void setTilePosition(float x, float y);

    Resource * getBase(){ return base; };
    //void checkCollisions(sf::RenderTarget & target);

};

#endif //OOPPROJECT_ENEMY_H
