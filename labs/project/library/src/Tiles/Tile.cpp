//
// Created by specklew on 09.01.2022.
//

#include "Tiles/Tile.h"

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
    this->sprite.setPosition(x*16, y*16);
}

void Tile::render(sf::RenderTarget & renderTarget) {
    renderTarget.draw(this->sprite);
}

