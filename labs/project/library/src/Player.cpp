//
// Created by student on 12/16/21.
//
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Tiles/TileRegistry.h"

Player::Player(float x , float y) {

    if(!this->textureSheet.loadFromFile("../../textures/player.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }

    this->sprite.setTexture(this->textureSheet);
    this->sprite.setPosition(x,y);
    this->sprite.setOrigin(this->sprite.getTextureRect().width/2, this->sprite.getTextureRect().height);
}

Player::~Player() {

}

void Player::move(const float dir_x, const float dir_y) {

    if(lockMovement[1] && dir_x > 0) return;
    if(lockMovement[3] && dir_x < 0) return;

    this->velocity.x += dir_x * acceleration;

    if (std::abs(this->velocity.x) > this->maxVelocity) {
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
}
void Player::jump(const float dir_x, const float dir_y) {
    this->velocity.x += dir_x * acceleration;
    this->velocity.y +=dir_y * gravity;
    if(std::abs(this->velocity.x) > this->maxVelocity){
        this->velocity.x = this->maxVelocity * ((this->velocity.x < 0.f) ? -1.f : 1.f);
    }
    if(std::abs(this->velocity.y) > this->maxVelocity){
        this->velocity.y = this->maxVelocity * ((this->velocity.y < 0.f) ? -1.f : 1.f);
    }
}
void Player::stop(const float dir_x, const float dir_y) {
    //this->velocity.x -= dir_x * acceleration;
    for(int i=0; i<3 ; i++)
    {
        this->velocity.x -= dir_x * i *acceleration;
    }
}

void Player::update(sf::RenderTarget & target){

    this->updatePhysics();
    this->updateMovement();
    this->windowBounds(target);
}

void Player::updatePhysics() {

    if(!lockMovement[2]) velocity.y += gravity/100;
    this->sprite.move(velocity);
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        if(!this->textureSheet.loadFromFile("../../textures/marioLeft.png")){
            std::cout << "ERROR: Could not load texture" << "\n";
        }
        this->sprite.setTexture(this->textureSheet);
        this->move(-1,0);
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        if(!this->textureSheet.loadFromFile("../../textures/player.png")){
            std::cout << "ERROR: Could not load texture" << "\n";
        }
        this->sprite.setTexture(this->textureSheet);
        this->move(1,0);
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->velocity.x=0;;
    }

    if(sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::W)){
            this->jump(0,-1);

        }
}

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}

sf::FloatRect Player::getPlayerBounds() {
    return this->sprite.getGlobalBounds();
}

void Player::setPositionX(float x) {
    this->sprite.setPosition(x, this->sprite.getPosition().y);
}

void Player::setPositionY(float y) {
    this->sprite.setPosition(this->sprite.getPosition().x, y);
}

void Player::windowBounds(sf::RenderTarget & target) {

    //Get all the tiles from the current level:
    Game * game = Game::GetInstance();
    Level * currentLevel = game->getCurrentLevel();
    Tile** allTiles = currentLevel->getAllTiles();

    //Get the tile preset that is not solid:
    TileRegistry * tileRegistry = TileRegistry::GetInstance();
    TilePreset * airPreset = tileRegistry->getPresetById(0);

    for (int i = 0; i < currentLevel->getLevelWidth(); ++i) {
        for (int j = 0; j < currentLevel->getLevelLength(); ++j) {
            sf::FloatRect tileBounds = allTiles[i][j].getGlobalBounds();
            //Check if player intersects with any tile in the level


            if(tileBounds.intersects(getPlayerBounds()) && allTiles[i][j].getTilePreset() != airPreset)
            {
                float tileLeft = tileBounds.left;
                float tileRight = tileBounds.left + tileBounds.width;
                float tileTop = tileBounds.top;
                float tileBottom = tileBounds.top + tileBounds.height;
                sf::Vector2f tilePos(tileLeft + tileBounds.width / 2, tileTop + tileBounds.height / 2);

                float playerLeft = getPlayerBounds().left;
                float playerRight = getPlayerBounds().left + getPlayerBounds().width;
                float playerTop = getPlayerBounds().top;
                float playerBottom = getPlayerBounds().top + getPlayerBounds().height;

                sf::Vector2f delta = tilePos - this->getPos();

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
                    if(intersectX > 0) lockMovement[1] = true; //Block movement to the right
                    else lockMovement[3] = true; //Block movement to the left
                }
                else{
                    setPositionY(this->sprite.getPosition().y - intersectY - 0.1f);
                    if(intersectY > 0)lockMovement[2] = true; //Block movement down
                    else lockMovement[0] = true; //Block movement up
                    velocity.y -= velocity.y;
                }

                if(intersectX == 0.0f) {
                    lockMovement[1] = false;
                    lockMovement[3] = false;
                }
                if(intersectY == 0.0f) {
                    lockMovement[0] = false;
                    lockMovement[2] = false;
                }

                /*if(playerBoundsRight >= tileLeft && playerBoundsLeft <= tileRight){
                    if(velocity.y > 0){
                        setPositionY(tileTop);
                        velocity.y = 0;
                    }
                    else if(velocity.y < 0 && getPlayerBounds().top > tileTop){
                        setPositionY(tileBottom + getPlayerBounds().height);
                        velocity.y = 2;
                    }
                }
                else{
                    if(velocity.y > 1.0f && !onGround || velocity.y < 1.0f && !onGround){
                        if(this->getPos().x > tilePos.x) setPositionX(tileRight + getPlayerBounds().width / 2);
                        else setPositionX(tileLeft - getPlayerBounds().width / 2);

                        stuckOn = true;
                        velocity.x = 0;
                    }
                }*/
/*                //If the player bottom is below the surface of the tile
                if (tileBounds.top > getPlayerBounds().top - getPlayerBounds().height) {

                    //If the player top is above the surface of tile
                    if (tileBounds.top - tileBounds.height > getPlayerBounds().top) {
                        this->sprite.setPosition(
                                this->sprite.getPosition().x,
                                tileBounds.top - getPlayerBounds().height - 0.1f
                                );
                        this->velocity.y = 0;
                    }
                    //If the player top is below the surface of tile
                    else{
                        this->sprite.setPosition(
                                this->sprite.getPosition().x,
                                tileBounds.top + tileBounds.height + 0.1f
                                );
                        this->velocity.y = 0;
                    }
                }
                else
                if (tileBounds.left > getPlayerBounds().left - getPlayerBounds().width) {

                    //If the player top is above the surface of tile
                    if (tileBounds.left - tileBounds.width > getPlayerBounds().left) {
                        this->sprite.setPosition(
                                tileBounds.left - getPlayerBounds().width - 0.1f,
                                this->sprite.getPosition().y
                        );
                        this->velocity.y = 0;
                    }
                        //If the player top is below the surface of tile
                    else {
                        this->sprite.setPosition(
                                tileBounds.left + tileBounds.width + 0.1f,
                                this->sprite.getPosition().y
                        );
                        this->velocity.y = 0;
                    }
                }*/
            }
            lockMovement[0] = false;
            lockMovement[1] = false;
            lockMovement[2] = false;
            lockMovement[3] = false;
            /*else {
                if(onGround){
                    onGround = false;
                    velocity.y = -2.0f;
                }
                if(stuckOn){
                    if (abs(this->getPos().x - tilePos.x) > 60 || abs(this->getPos().y - tilePos.y) > 100) {
                        stuckOn = false;
                    }
                }
            }*/
        }
    }

/*
    if(getPlayerBounds().left <=0.f)
        this->sprite.setPosition(0.f , this->sprite.getPosition().y);

    else if(getPlayerBounds().left+getPlayerBounds().width>=target.getSize().x)
        this->sprite.setPosition(target.getSize().x - getPlayerBounds().width,getPlayerBounds().top);

    if(getPlayerBounds().top+getPlayerBounds().height >= target.getSize().y-100.f)
        this->sprite.setPosition(getPlayerBounds().left, target.getSize().y - getPlayerBounds().height - 100.f);
*/

}