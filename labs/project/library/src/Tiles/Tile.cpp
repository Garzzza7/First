//
// Created by specklew on 09.01.2022.
//

#include "Tiles/Tile.h"
#include "Tiles/TileRegistry.h"

Tile::Tile(){

}

Tile::Tile(TilePreset * type) {

    this->type = type;
    this->sprite.setTexture(type->texture);
    this->sprite.setTextureRect(type->getRect());
    this->sprite.setScale(1,1);

}

Tile::~Tile() {

}

void Tile::setTilePosition(int x, int y) {
    TileRegistry * tileRegistry = TileRegistry::GetInstance();
    this->sprite.setPosition(x*tileRegistry->getTileSize(), y*tileRegistry->getTileSize());
}

void Tile::render(sf::RenderTarget & renderTarget) {
    renderTarget.draw(this->sprite);
}

sf::FloatRect Tile::getGlobalBounds() {
    return this->sprite.getGlobalBounds();
}

TilePreset * Tile::getTilePreset() {
    return this->type;
}

