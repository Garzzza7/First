#ifndef OOPPROJECT_TILEPRESET_H
#define OOPPROJECT_TILEPRESET_H

#include <SFML/Graphics.hpp>

class TilePreset{

    sf::IntRect rect;

public:
    sf::Texture texture;

    TilePreset(std::string textureAddress, sf::IntRect rect);
    sf::IntRect getRect();

};

#endif //OOPPROJECT_TILEPRESET_H
