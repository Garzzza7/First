#ifndef OOPPROJECT_ENTITY_H
#define OOPPROJECT_ENTITY_H

#include <SFML/Graphics.hpp>

#include "Resources/ResourceRegistry.h"
#include "Resources/Resource.h"
#include "Tiles/Tile.h"

class Entity{

    Resource * base;
    //virtual CollisionStrategy strategy = 0;
    int id;

    int hp;
    int damage;

    sf::FloatRect nextPos;

    void setPositionX(float x);
    void setPositionY(float y);

protected:
    //Physics:
    sf::Vector2f velocity{0,0};
    float maxVelocity{2.0f};
    float acceleration{0.2f};
    float gravity{10.f};

    sf::Sprite sprite1;

    bool flipMovement{false};

public:
    Entity(Resource * base, int hp, int damage, float acceleration);
    //sf::Event lol;
    //Update functions run every frame.
    virtual void update();
    virtual void updatePhysics()=0;
    virtual void updateMovement()=0;
    virtual int getID();
    //virtual void dealDMG()=0;

    sf::FloatRect getEnemyBounds();

    friend class Player;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    virtual void move(const float dir_x, const float dir_y)=0;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

    void checkCollisions(Tile **tiles, int levelHeight, int levelLength);

    void setPosition(float x, float y);
    void setPosition(sf::Vector2f position);

    void setTilePosition(float x, float y);

    void collisionwithmario();

    Resource * getBase(){ return base; };

    //void checkCollisions(sf::RenderTarget & target);

    virtual int getDamage();

};

#endif //OOPPROJECT_ENTITY_H
