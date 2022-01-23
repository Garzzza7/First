#ifndef OOPPROJECT_OBJECTBASE_H
#define OOPPROJECT_OBJECTBASE_H

#include <SFML/Graphics.hpp>
#include "AnimatedGif.h"

enum ObjectType{
    TILE,
    ANIMATED_TILE,
    ENTITY
};

class ObjectBase{

    ObjectType type;
    sf::IntRect rect;

public:
    sf::Texture texture;
    AnimatedGif gif;

    ObjectBase(ObjectType type, std::string textureAddress, sf::IntRect rect);

    ObjectType getType(){return type;}
    sf::IntRect getRect(){return rect;};

};

#endif //OOPPROJECT_OBJECTBASE_H
