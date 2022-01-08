#ifndef OOPPROJECT_PLAYER_H
#define OOPPROJECT_PLAYER_H

#include <SFML/Graphics.hpp>

class Player{
    sf::Sprite sprite;
    sf::Texture textureSheet;

public:
    Player();
    ~Player();
    void render(sf::RenderTarget & target);

};

#endif //OOPPROJECT_PLAYER_H
