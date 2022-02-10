#ifndef OOPPROJECT_LEVEL_H
#define OOPPROJECT_LEVEL_H

#include <memory>
#include <fstream>

#include "Resources/ResourceRegistry.h"
#include "Tiles/Tile.h"

#include "Entities/EntityFactory.h"
#include "Entities/Entity.h"

//#include "Player.h"

class Level{

    Tile ** tiles;

    std::unique_ptr<EntityFactory> enemyFactory;
    std::vector<Entity*> enemies;

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
