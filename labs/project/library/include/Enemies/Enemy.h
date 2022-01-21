#ifndef OOPPROJECT_ENEMY_H
#define OOPPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>
#include "Tiles/ObjectBase.h"

class Enemy{

    ObjectBase * base;

    int hp;
    int damage;

protected:
    //Physics:
    sf::Vector2f velocity{0,0};
    float maxVelocity{2.0f};
    float acceleration{0.2f};
    float gravity{10.f};

    sf::Sprite sprite;

public:
    Enemy(ObjectBase * base,int hp,int damage,float acceleration);
    ~Enemy();
    //sf::Event lol;
    //Update functions run every frame.
    virtual void update()=0;
    virtual void updatePhysics()=0;
    virtual void updateMovement()=0;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    virtual void move(const float dir_x, const float dir_y)=0;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);

    void setTilePosition(float x, float y);

    ObjectBase * getBase(){ return base; };
    //void checkCollisions(sf::RenderTarget & target);

};

#endif //OOPPROJECT_ENEMY_H
