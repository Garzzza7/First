//
// Created by specklew on 20.01.2022.
//

#include "Tiles/ObjectRegistry.h"

ObjectRegistry* ObjectRegistry::instance{nullptr};
std::mutex ObjectRegistry::mutex;

ObjectRegistry::ObjectRegistry() {
    initObjects();
}

ObjectRegistry * ObjectRegistry::GetInstance()
{
    std::lock_guard<std::mutex> lock(mutex);
    if (instance == nullptr)
    {
        instance = new ObjectRegistry();
    }
    return instance;
}


void ObjectRegistry::initObjects() {

    sf::IntRect basicRect(0, 0, tileSize, tileSize);

    auto* airTile = new ObjectBase(TILE, relativeTexturePath + "Air.png", basicRect);
    auto* groundTile = new ObjectBase(TILE, relativeTexturePath + "Ground.png", basicRect);
    auto* brickTile = new ObjectBase(TILE, relativeTexturePath + "BrickBlockBrown.png", basicRect);
    auto* blockTile = new ObjectBase(TILE, relativeTexturePath + "Block.png", basicRect);
    auto* goombaEntity = new ObjectBase(ENTITY, relativeTexturePath + "LittleGoomba.gif", basicRect);
    auto* pplantEntity = new ObjectBase(ENTITY, relativeTexturePath + "PiranhaPlant.gif", basicRect);

    objectBases.push_back(airTile);
    objectBases.push_back(groundTile);
    objectBases.push_back(brickTile);
    objectBases.push_back(blockTile);
    objectBases.push_back(goombaEntity);
    objectBases.push_back(pplantEntity);
}

void ObjectRegistry::deleteObjects() {
    for(auto object : objectBases){
        delete object;
    }
}

unsigned int ObjectRegistry::getTileSize() {
    return tileSize;
}

ObjectBase * ObjectRegistry::getPresetById(int id) {
    return objectBases.at(id);
}
