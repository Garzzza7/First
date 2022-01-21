//
// Created by specklew on 14.01.2022.
//

#include <Tiles/ObjectBase.h>
#include <iostream>

ObjectBase::ObjectBase(ObjectType type, std::string textureAddress, sf::IntRect rect) {
    this->type = type;
    this->rect = rect;

    if(!this->texture.loadFromFile("../../textures/" + textureAddress)){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
}

