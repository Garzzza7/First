#include "Level.h"


Level::Level(const std::string fileName) {

    ResourceRegistry * resourceRegistry = ResourceRegistry::GetInstance();
    enemyFactory = std::make_unique<EnemyFactory>();

    std::fstream levelFile;
    levelFile.open( "../../levels/" + fileName, std::ios::in);

    if(levelFile.is_open())
    {
        int i = 0;
        std::string str;
        while(std::getline(levelFile, str)){
            if(i == 0){
                int j = 0;
                bool done = false;
                std::string x;
                for(char& c : str) {
                    j++;
                    if(c == ';' && !done){
                        length = stoi(x);
                        done = true;
                        x = "";
                        continue;
                    }
                    if(c == ';'){
                        height = stoi(x);
                        initArray();
                        continue;
                    }
                    x += c;
                }
                i++;
                continue;
            }

            //Start assigning tiles.
            int j = 0;
            for(char c : str) {

                int num = c - 48;

                if(resourceRegistry->getPresetById(num)->getType() == TILE) {
                    Tile *newTile = new Tile(resourceRegistry->getPresetById(num));
                    tiles[i - 1][j] = *newTile;
                }else if(resourceRegistry->getPresetById(num)->getType() == ENTITY){
                    Tile *newTile = new Tile(resourceRegistry->getPresetById(0));
                    tiles[i - 1][j] = *newTile;

                    Enemy * enemy = enemyFactory->CreateEnemy(num);


                    enemy->setTilePosition(j, i);

                    enemies.push_back(enemy);
                }

                j++;
            }

            i++;
        }
    }
    else
    {
        throw std::runtime_error("The level could not be found! Level file passed: " + fileName);
    }
    initTilePositions();
}

void Level::initArray() {
    tiles = new Tile* [height];

    for (int i=0; i < height; ++i)
    {
        tiles[i] = new Tile[length];
    }
}

void Level::initTilePositions() {
    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < length; ++j){
            tiles[i][j].setTilePosition(j, i);
        }
    }
}

void Level::render(sf::RenderTarget & renderTarget) {

    for(int i = 0; i < height; ++i) {
        for(int j = 0; j < length; ++j){
            tiles[i][j].render(renderTarget);
        }
    }

    for(auto enemy : enemies){
        enemy->render(renderTarget);
    }
}

void Level::update() {
    for(auto enemy : enemies){
        enemy->update();
        enemy->checkCollisions(this->tiles, this->height, this->length);
    }
}

Level::~Level() {
    for(int i=0; i < height; i++)    //To delete the inner arrays
        delete [] tiles[i];
    delete [] tiles;
    for(auto enemy : enemies) {
        delete enemy;
    }
}