#ifndef OOPPROJECT_ENEMY_H
#define OOPPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy{

    int hp;
    int damage;
    std::string id;

protected:
//Physics:
sf::Vector2f velocity{0,0};
    float maxVelocity{2.0f};
    float acceleration{0.2f};
    float gravity{10.f};
public:
    Enemy(std::string id,int hp,int damage,float acceleration);
    ~Enemy();
    //sf::Event lol;
    //Update functions run every frame.
    virtual void update(sf::RenderTarget & target)=0;
    virtual void updatePhysics()=0;
    virtual void updateMovement()=0;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    virtual void move(const float dir_x, const float dir_y)=0;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    virtual void render(sf::RenderTarget & target)=0;

    //void windowBounds(sf::RenderTarget & target);

};

#endif //OOPPROJECT_ENEMY_H
