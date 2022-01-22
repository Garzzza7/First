//
// Created by specklew on 15.01.2022.
//

#include <cstring>
#include <fstream>
#include <iostream>

#include "Level.h"
#include "Tiles/ObjectRegistry.h"
#include "Enemies/Goomba.h"
#include "Enemies/PPlant.h"

Level::Level(const std::string fileName) {

    ObjectRegistry * tileRegistry = ObjectRegistry::GetInstance();

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
                        width = stoi(x);
                        done = true;
                        x = "";
                        continue;
                    }
                    if(c == ';'){
                        length = stoi(x);
                        initArray();
                        continue;
                    }
                    x += c;
                }
                i++;
                continue;
            }

            //Start assigning tiles
            int j = 0;
            for(char c : str) {

                int num = atoi(&c);

                if(tileRegistry->getPresetById(num)->getType() == TILE) {
                    Tile *newTile = new Tile(tileRegistry->getPresetById(num));
                    tiles[j][i - 1] = *newTile;
                }else if(tileRegistry->getPresetById(num)->getType() == ENTITY){
                    Tile *newTile = new Tile(tileRegistry->getPresetById(0));
                    tiles[j][i - 1] = *newTile;

                    Enemy * enemy;

                    //I wanted to do it better, but I have no idea how...
                    if(num == 2){
                        enemy = new Goomba(tileRegistry->getPresetById(num),1,3,4);
                    }
                    if(num == 3){
                        enemy = new PPlant(tileRegistry->getPresetById(num),1,3);
                    }

                    enemy->setTilePosition(j, i-1);

                    enemies.push_back(enemy);
                }

                j++;
            }

            i++;
        }
    }
    else
    {
        std::cout << "Level file not found" << std::endl;
        initArray();
    }
    initTilePositions();
}

void Level::initArray() {
    tiles = new Tile* [width];

    for (int i=0; i<width; i++)
    {
        tiles[i] = new Tile[length];
    }
}

void Level::initTilePositions() {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
            tiles[i][j].setTilePosition(i, j);
        }
    }
}

void Level::render(sf::RenderTarget & renderTarget) {
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
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
        enemy->checkCollisions(this->tiles, this->width, this->length);
    }
}

Level::~Level() {
    for(int i=0;i<width;i++)    //To delete the inner arrays
        delete [] tiles[i];
    delete [] tiles;
    for(auto enemy : enemies){
        delete enemy;
    }
}

void Level::renderEnemy(sf::RenderTarget &target) {

        //target.draw(this->enemies);

}

Tile** Level::getAllTiles() {

    return tiles;
}

int Level::getLevelWidth() {
    return width;
}

int Level::getLevelLength() {
    return length;
}
