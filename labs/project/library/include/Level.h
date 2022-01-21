#ifndef OOPPROJECT_LEVEL_H
#define OOPPROJECT_LEVEL_H

#include <Enemies/Enemy.h>
#include "Tiles/Tile.h"

class Level{

    Tile ** tiles;
    std::vector<Enemy> enemies;
    int length{10};
    int width{10};

public:

    Level(const std::string fileName);
    ~Level();

    void initArray();
    void initTilePositions();

    void render(sf::RenderTarget & renderTarget);

    void update();
    void renderEnemy(sf::RenderTarget & target);

};

#endif //OOPPROJECT_LEVEL_H
