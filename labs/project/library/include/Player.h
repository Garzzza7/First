#ifndef OOPPROJECT_PLAYER_H
#define OOPPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>

class Player{
    sf::Sprite sprite;
    sf::Texture textureSheet;
    sf::RectangleShape mario;
    void createShape();

    //Physics:
    sf::Vector2f velocity{0,0};
    float gravity{0.f};
    float acceleration{0.2f};
    float maxVelocity{2.0f};
    float friction{0.5f};
    sf::Event event;
    bool IsJumping {false};

public:
    Player();
    ~Player();
    sf::Event lol;
    //Update functions run every frame.
    void update();
    void updatePhysics();
    void updateMovement();

    void move(const float dir_x, const float dir_y);
    void jump(const float dir_x, const float dir_y);
    void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

};

#endif //OOPPROJECT_PLAYER_H
