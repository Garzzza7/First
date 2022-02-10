#ifndef OOPPROJECT_LEVEL_H
#define OOPPROJECT_LEVEL_H

#include <memory>
#include <fstream>

#include "Resources/ResourceRegistry.h"
#include "Tiles/Tile.h"

#include "Enemies/EnemyFactory.h"
#include "Enemies/Enemy.h"

//#include "Player.h"

class Level{

    Tile ** tiles;

    std::unique_ptr<EnemyFactory> enemyFactory;
    std::vector<Enemy*> enemies;

    sf::Texture backgroundTexture;
    std::vector<std::shared_ptr<sf::Sprite>> backgrounds;

    int height{10};
    int length{10};

    //Private methods:
    void initBackgroundTexture();

public:

    friend class Player;
    Level(const std::string fileName);
    ~Level();

    void initArray();
    void initTilePositions();

    void render(sf::RenderTarget & renderTarget);

    Tile** getAllTiles(){return tiles;};
    int getLevelHeight() {return height;};
    int getLevelLength() {return length;};

    void update();
};

#endif //OOPPROJECT_LEVEL_H
