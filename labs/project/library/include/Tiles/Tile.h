#ifndef OOPPROJECT_TILE_H
#define OOPPROJECT_TILE_H

#include <SFML/Graphics.hpp>
#include "TilePreset.h"

class Tile{

    TilePreset * type;

    sf::Sprite sprite;

public:

    Tile();
    Tile(TilePreset * type);
    ~Tile();
    void update();
    void setTilePosition(int x, int y);
    void render(sf::RenderTarget & renderTarget);
    void getGlobalBounds();
    //void getCollisionEffect();
    TilePreset getTilePreset();
};

#endif //OOPPROJECT_TILE_H
