//
// Created by specklew on 14.01.2022.
//

#include "Tiles/ObjectBase.h"

ObjectBase::ObjectBase(ObjectType type, std::string textureAddress, sf::IntRect rect) : gif(textureAddress.c_str()){
    this->type = type;
    this->rect = rect;

    if(!this->texture.loadFromFile(textureAddress)){
        throw std::runtime_error("Could not load texture at: " + textureAddress);
    }
}

