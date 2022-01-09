#ifndef OOPPROJECT_TILE_H
#define OOPPROJECT_TILE_H

#include <SFML/Graphics.hpp>

class Tile{

    sf::Sprite sprite;
    sf::Texture texture;
    sf::Vector2i position;

public:

    Tile();
};

#endif //OOPPROJECT_TILE_H
