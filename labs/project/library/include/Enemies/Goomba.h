#ifndef OOPPROJECT_GOOMBA_H
#define OOPPROJECT_GOOMBA_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <ctime>

class Goomba : public Enemy{
protected:
    int hp{1};
    int damage{1};
    float acceleration;
    int id{4};

public:
    Goomba(Resource * base);

    ~Goomba();
  //  void updatePhysics();
    //void updateMovement();
    //void move(const float dir_x, const float dir_y) override;

    //sf::Event lol;
    //Update functions run every frame.
     void updatePhysics() override ;
     void updateMovement() override;
    int getID() override {return id;};

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    void move(const float dir_x, const float dir_y) override;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);
    //int getDamage() override;

    //void checkCollisions(sf::RenderTarget & target);

};

#endif //OOPPROJECT_GOOMBA_H
