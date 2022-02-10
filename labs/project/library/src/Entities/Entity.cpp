#include "Entities/Entity.h"

Entity::Entity(Resource * base, int hp, int damage, float acceleration) {
    this->base = base;
    this->hp = hp;
    this->damage = damage;
    this->acceleration = acceleration;

    this->sprite1.setTexture(Entity::getBase()->getTexture());
    this->sprite1.setOrigin(this->sprite1.getTextureRect().width/2, this->sprite1.getTextureRect().height);
}

void Entity::render(sf::RenderTarget &target){
    target.draw(this->sprite1);
}


void Entity::update() {
    this->updatePhysics();
    this->updateMovement();
    this->base->getGif().update(this->sprite1);

}

void Entity::updatePhysics() {
    velocity.y += gravity/1000;
    //this->goomba.move(velocity);
}
//void Entity::updateMovement() {}

void Entity::checkCollisions(Tile **allTiles, int levelHeight, int levelLength) {

    //Get the tile preset that is not solid:
    ResourceRegistry * tileRegistry = ResourceRegistry::GetInstance();
    Resource * airPreset = tileRegistry->getPresetById(0);

    for (int i = 0; i < levelHeight; ++i) {
        for (int j = 0; j < levelLength; ++j) {
            sf::FloatRect tileBounds = allTiles[i][j].getGlobalBounds();
            //Check if player intersects with any tile in the level

            if(tileBounds.intersects(this->sprite1.getGlobalBounds()) && allTiles[i][j].getTilePreset() != airPreset){

                float tileLeft = tileBounds.left;
                float tileRight = tileBounds.left + tileBounds.width;
                float tileTop = tileBounds.top;
                float tileBottom = tileBounds.top + tileBounds.height;
                sf::Vector2f tilePos(tileLeft + tileBounds.width / 2, tileTop + tileBounds.height / 2);

                float playerLeft = this->sprite1.getGlobalBounds().left;
                float playerRight = this->sprite1.getGlobalBounds().left + this->sprite1.getGlobalBounds().width;
                float playerTop = this->sprite1.getGlobalBounds().top;
                float playerBottom = this->sprite1.getGlobalBounds().top + this->sprite1.getGlobalBounds().height;

                sf::Vector2f delta = tilePos - this->sprite1.getPosition();

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
                    flipMovement = !flipMovement;
                    setPositionX(this->sprite1.getPosition().x - intersectX);
                }
                else{
                    setPositionY(this->sprite1.getPosition().y - intersectY - 0.1f);
                    velocity.y -= velocity.y;
                }
            }
        }
    }
}

//Private setters:

void Entity::setPositionX(float x) {
    this->sprite1.setPosition(x, this->sprite1.getPosition().y);
}
void Entity::collisionwithmario() {


}

void Entity::setPositionY(float y) {
    this->sprite1.setPosition(this->sprite1.getPosition().x, y);
}

//Public setters:

void Entity::setPosition(float x, float y) {
    this->sprite1.setPosition(x, y);
}

void Entity::setPosition(sf::Vector2f position) {
    this->sprite1.setPosition(position);
}

void Entity::setTilePosition(float x, float y) {
    ResourceRegistry * resourceRegistry = ResourceRegistry::GetInstance();
    this->sprite1.setPosition(x * (float)resourceRegistry->getTileSize(), y * (float)resourceRegistry->getTileSize());
}

sf::FloatRect Entity::getEnemyBounds() {
    return this->base->getResourceBounds();
}
int Entity::getID() {
    return id;
}
int Entity::getDamage() {
    return damage;
}

//void Entity::kill() {
  //  delete enemy;
//}

