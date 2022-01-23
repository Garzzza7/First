#include <iostream>
#include "Enemies/Enemy.h"
#include "Tiles/ObjectRegistry.h"


Enemy::Enemy(ObjectBase * base,int hp,int damage,float acceleration) {
    this->base = base;
    this->hp = hp;
    this->damage = damage;
    this->acceleration = acceleration;

    this->sprite.setTexture(Enemy::getBase()->texture);
    this->sprite.setOrigin(this->sprite.getTextureRect().width/2, this->sprite.getTextureRect().height);
}

void Enemy::render(sf::RenderTarget &target){
    target.draw(this->sprite);
}

void Enemy::update() {
    this->updatePhysics();
    this->updateMovement();
    this->base->gif.update(this->sprite);
}

void Enemy::updatePhysics() {
    velocity.y += gravity/1000;
    //this->goomba.move(velocity);
}
void Enemy::updateMovement() {}

void Enemy::checkCollisions(Tile **allTiles, int levelWidth, int levelLength) {

    //Get the tile preset that is not solid:
    ObjectRegistry * tileRegistry = ObjectRegistry::GetInstance();
    ObjectBase * airPreset = tileRegistry->getPresetById(0);

    for (int i = 0; i < levelWidth; ++i) {
        for (int j = 0; j < levelLength; ++j) {
            sf::FloatRect tileBounds = allTiles[i][j].getGlobalBounds();
            //Check if player intersects with any tile in the level


            if(tileBounds.intersects(this->sprite.getGlobalBounds()) && allTiles[i][j].getTilePreset() != airPreset)
            {
                float tileLeft = tileBounds.left;
                float tileRight = tileBounds.left + tileBounds.width;
                float tileTop = tileBounds.top;
                float tileBottom = tileBounds.top + tileBounds.height;
                sf::Vector2f tilePos(tileLeft + tileBounds.width / 2, tileTop + tileBounds.height / 2);

                float playerLeft = this->sprite.getGlobalBounds().left;
                float playerRight = this->sprite.getGlobalBounds().left + this->sprite.getGlobalBounds().width;
                float playerTop = this->sprite.getGlobalBounds().top;
                float playerBottom = this->sprite.getGlobalBounds().top + this->sprite.getGlobalBounds().height;

                sf::Vector2f delta = tilePos - this->sprite.getPosition();

                float intersectX = 0.0f, intersectY = 0.0f;

                if(delta.y > 0)
                {
                    if(delta.x > 0)
                    {
                        intersectX = playerRight - tileLeft;
                        intersectY = playerBottom - tileTop;
                    }
                    else
                    {
                        intersectX = playerLeft - tileRight;
                        intersectY = playerBottom - tileTop;
                    }
                }
                else
                {
                    if(delta.x > 0)
                    {
                        intersectX = playerRight - tileLeft;
                        intersectY = playerTop - tileBottom;
                    }
                    else
                    {
                        intersectX = playerLeft - tileRight;
                        intersectY = playerTop - tileBottom;
                    }
                }

                if(std::abs(intersectX) < std::abs(intersectY)){
                    setPositionX(this->sprite.getPosition().x - intersectX - 0.1f);
                }
                else{
                    setPositionY(this->sprite.getPosition().y - intersectY - 0.1f);
                    velocity.y -= velocity.y;
                }
            }
        }
    }

}

//Private setters:

void Enemy::setPositionX(float x) {
    this->sprite.setPosition(x, this->sprite.getPosition().y);
}

void Enemy::setPositionY(float y) {
    this->sprite.setPosition(this->sprite.getPosition().x, y);
}

//Public setters:

void Enemy::setPosition(float x, float y) {
    this->sprite.setPosition(x, y);
}

void Enemy::setPosition(sf::Vector2f position) {
    this->sprite.setPosition(position);
}

void Enemy::setTilePosition(float x, float y) {
    ObjectRegistry * objectRegistry = ObjectRegistry::GetInstance();
    this->sprite.setPosition(x * objectRegistry->getTileSize(), y * objectRegistry->getTileSize());
}
