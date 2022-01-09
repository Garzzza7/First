#ifndef OOPPROJECT_PLAYER_H
#define OOPPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>

class Player{
    sf::Sprite sprite;
    sf::Texture textureSheet;

    //Physics:
    sf::Vector2f velocity{0,0};
    float gravity{9.81f};
    float acceleration{0.2f};
    float maxVelocity{2.0f};

public:
    Player();
    ~Player();

    //Update functions run every frame.
    void update();
    void updatePhysics();
    void updateMovement();

    void move(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

};

#endif //OOPPROJECT_PLAYER_H
