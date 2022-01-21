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
    float gravity{10.f};
    float acceleration{0.2f};
    float maxVelocity{2.0f};
    float friction{0.5f};
    sf::Event event;
    bool IsJumping {};

public:
    Player(float x , float y);
    ~Player();
    sf::Event lol;
    //Update functions run every frame.
    void update(sf::RenderTarget & target);
    void updatePhysics();
    void updateMovement();

    sf::Vector2f GetPos() {return sprite.getPosition();};

    void move(const float dir_x, const float dir_y);
    void jump(const float dir_x, const float dir_y);
    void stop(const float dir_x, const float dir_y);

    void render(sf::RenderTarget & target);

    void windowBounds(sf::RenderTarget & target);

};

#endif //OOPPROJECT_PLAYER_H
