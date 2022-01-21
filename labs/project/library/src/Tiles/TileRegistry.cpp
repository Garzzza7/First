//
// Created by specklew on 20.01.2022.
//

#include "Tiles/TileRegistry.h"

TileRegistry* TileRegistry::instance{nullptr};
std::mutex TileRegistry::mutex;

TileRegistry::TileRegistry() {
    initTiles();
}

TileRegistry * TileRegistry::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr)
    {
        instance = new TileRegistry();
    }
    return instance;
}


void TileRegistry::initTiles() {

    sf::IntRect basicRect(0, 0, tileSize, tileSize);

    auto* airTile = new TilePreset("air.png", basicRect);
    auto* brickTile = new TilePreset("brick.png", basicRect);

    tilePresets.push_back(airTile);
    tilePresets.push_back(brickTile);

}

void TileRegistry::deleteTiles() {
    for(auto tile : tilePresets){
        delete tile;
    }
}

unsigned int TileRegistry::getTileSize() {
    return tileSize;
}

TilePreset * TileRegistry::getPresetById(int id) {
    return tilePresets.at(id);
}
