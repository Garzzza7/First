#ifndef OOPPROJECT_GOOMBA_H
#define OOPPROJECT_GOOMBA_H

#include <SFML/Graphics.hpp>
#include "Enemy.h"
#include <ctime>

class Goomba : public Enemy{
private:
    sf::Sprite goomba;
    sf::Texture textureSheet;

public:
    Goomba(std::string id,int hp,int damage,float acceleration);

    ~Goomba();
  //  void updatePhysics();
    //void updateMovement();
    //void move(const float dir_x, const float dir_y) override;

    //sf::Event lol;
    //Update functions run every frame.
    void update(sf::RenderTarget & target) override;
     void updatePhysics() override ;
     void updateMovement() override;

    //sf::Vector2f GetPos() {return sprite.getPosition();};

    void move(const float dir_x, const float dir_y) override;
    //void jump(const float dir_x, const float dir_y);
    //void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target) override;

    //void windowBounds(sf::RenderTarget & target);
};

#endif //OOPPROJECT_GOOMBA_H
