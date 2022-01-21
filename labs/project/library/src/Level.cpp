//
// Created by specklew on 15.01.2022.
//

#include <cstring>
#include <fstream>
#include <iostream>

#include "Level.h"
#include "Tiles/TileRegistry.h"

Level::Level(const std::string fileName) {

    TileRegistry * tileRegistry = TileRegistry::GetInstance();

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

                Tile* newTile = new Tile(tileRegistry->getPresetById(num));
                tiles[j][i-1] = *newTile;

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
}

Level::~Level() {
    for(int i=0;i<width;i++)    //To delete the inner arrays
        delete [] tiles[i];
    delete [] tiles;
}
void Level::renderEnemy(sf::RenderTarget &target) {

        //target.draw(this->enemies);

}
