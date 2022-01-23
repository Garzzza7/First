#ifndef OOPPROJECT_TILE_H
#define OOPPROJECT_TILE_H

#include <SFML/Graphics.hpp>
#include "Tiles/ObjectRegistry.h"
#include "ObjectBase.h"

class Tile{

    ObjectBase * type;
    sf::Sprite sprite;

public:

    Tile(){};
    Tile(ObjectBase * type);
    ~Tile();
    void update();

    void setTilePosition(int x, int y);
    void render(sf::RenderTarget & renderTarget);

    sf::FloatRect getGlobalBounds();
    ObjectBase * getTilePreset();
};

#endif //OOPPROJECT_TILE_H
