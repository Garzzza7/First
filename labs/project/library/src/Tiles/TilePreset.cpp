//
// Created by specklew on 14.01.2022.
//

#include <Tiles/TilePreset.h>
#include <iostream>

TilePreset::TilePreset(std::string textureAddress, sf::IntRect rect) {
    this->rect = rect;

    if(!this->texture.loadFromFile("../../textures/" + textureAddress)){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
}

sf::IntRect TilePreset::getRect() {
    return rect;
}
