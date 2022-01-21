#ifndef OOPPROJECT_LEVEL_H
#define OOPPROJECT_LEVEL_H

#include "Tiles/Tile.h"

class Level{

    Tile ** tiles;

    int length{10};
    int width{10};

public:

    Level(const std::string fileName);
    ~Level();

    void initArray();
    void initTilePositions();

    void render(sf::RenderTarget & renderTarget);

    Tile** getAllTiles();
    int getLevelWidth();
    int getLevelLength();

    void update();

};

#endif //OOPPROJECT_LEVEL_H
