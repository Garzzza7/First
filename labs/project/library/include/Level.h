#ifndef OOPPROJECT_LEVEL_H
#define OOPPROJECT_LEVEL_H

#include <memory>

#include "Resources/ResourceRegistry.h"
#include "Tiles/Tile.h"

#include "Enemies/EnemyFactory.h"
#include "Enemies/Enemy.h"

class Level{

    Tile ** tiles;

    std::unique_ptr<EnemyFactory> enemyFactory;
    std::vector<Enemy*> enemies;

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
    void renderEnemy(sf::RenderTarget & target);

};

#endif //OOPPROJECT_LEVEL_H
