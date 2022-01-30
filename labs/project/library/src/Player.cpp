//
// Created by student on 12/16/21.
//
#include <iostream>
#include "Player.h"
#include "Game.h"
#include "Resources/ResourceRegistry.h"

Player::Player(float x , float y) : gif("../../textures/Mario.gif"){

    if(!this->standingTexture.loadFromFile("../../textures/MarioStanding.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    if(!this->jumpingTexture.loadFromFile("../../textures/MarioJumping.png")){
        std::cout << "ERROR: Could not load texture" << "\n";
    }
    this->sprite.setTexture(this->standingTexture);
    this->sprite.setTextureRect({0, 0, (int)this->standingTexture.getSize().x, (int)this->standingTexture.getSize().y});
    this->sprite.setPosition(x,y);
    this->sprite.setOrigin(this->sprite.getTextureRect().width/2, this->sprite.getTextureRect().height);
}
/*
//Definitions of static classes.
Player * Player::instance{nullptr};
std::mutex Game::mutex;

//Locking the storage location using lock_guard.
Player * Player::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if(instance == nullptr){
        instance = new Player();
    }
    return instance;
}
*/
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
    this->updateAnimations();
    this->enemyCollisions(target);
    this->checkCollisions(target);
}

void Player::updatePhysics() {

    if(!lockMovement[2]) velocity.y += gravity/100;
    this->sprite.move(velocity);
}

void Player::updateMovement() {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        if(moveBoolDirection){
            this->sprite.scale(-1.0f, 1.0f);
            moveBoolDirection = false;
        }
        if(!lockMovement[3]) this->move(-1,0);
    }

    else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        if(!moveBoolDirection){
            this->sprite.scale(-1.0f, 1.0f);
            moveBoolDirection = true;
        }

        if(!lockMovement[1]) this->move(1,0);
    }
    if(!sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)){
        this->velocity.x=0;;
    }

    if(sf::Keyboard::isKeyPressed(::sf::Keyboard::Key::W) && (onGround || jumpCount < 2)){
            this->jump(0,-1);
            jumpCount += 1;//TODO: make holding the key "W" down count as a single input.
        }
}

void Player::updateAnimations() {
    if(std::abs(this->velocity.y) > 0.2f || !onGround){
        this->sprite.setTextureRect({0, 0, (int)this->jumpingTexture.getSize().x, (int)this->jumpingTexture.getSize().y});
        this->sprite.setTexture(this->jumpingTexture);
    }
    else if(std::abs(this->velocity.x) > 0.1f){
        this->gif.update(this->sprite);
        this->sprite.setTextureRect({0, 0, this->gif.getSize().x, this->gif.getSize().y});
    }
    else
    {
        this->sprite.setTextureRect({0, 0, (int)this->standingTexture.getSize().x, (int)this->standingTexture.getSize().y});
        this->sprite.setTexture(this->standingTexture);
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

void Player::checkCollisions(sf::RenderTarget & target) {

    //Get all the tiles from the current level:
    Game * game = Game::GetInstance();
    Level * currentLevel = game->getCurrentLevel();
    Tile** allTiles = currentLevel->getAllTiles();

    //Get the tile preset that is not solid:
    ResourceRegistry * tileRegistry = ResourceRegistry::GetInstance();
    Resource * airPreset = tileRegistry->getPresetById(0);

    for (int i = 0; i < currentLevel->getLevelWidth(); ++i) {
        for (int j = 0; j < currentLevel->getLevelLength(); ++j) {
            if(allTiles[i][j].getTilePreset() == airPreset) continue;
            sf::FloatRect tileBounds = allTiles[i][j].getGlobalBounds();
            //Check if player intersects with any tile in the level


            if(tileBounds.intersects(getPlayerBounds())){

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
                    setPositionX(this->sprite.getPosition().x - intersectX);
                    if(intersectX > 0) lockMovement[1] = true; //Block movement to the right
                    else lockMovement[3] = true; //Block movement to the left
                }
                else{
                    setPositionY(this->sprite.getPosition().y - intersectY - 0.1f);
                    if(intersectY > 0){
                        onGround = true;
                        jumpCount = 0;
                        lockMovement[2] = true; //Block movement down
                    }
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

            }
            else if(std::abs(velocity.y) > 0.2f){
                onGround = false;
            }
            lockMovement[0] = false;
            lockMovement[1] = false;
            lockMovement[2] = false;
            lockMovement[3] = false;
        }
    }
}
void Player::receivedmg(int dmg) {
    //playerhp-=dmg;
}

void Player::enemyCollisions(sf::RenderTarget & target) {
        Game * game = Game::GetInstance();
        Level * level = game->getCurrentLevel();


    for (auto  enemy : level->enemies)
    {
        sf::FloatRect playerBounds=getPlayerBounds();
        sf::FloatRect enemyBounds=enemy->getEnemyBounds();
        //if(enemyBounds.intersects(getPlayerBounds()))
        if(sprite.getGlobalBounds().intersects(enemy->sprite1.getGlobalBounds()))
        {
            //std::cout<<"asdasdasda"<<std::endl;
            //jump(-100.f,100.f);
            if(sprite.getGlobalBounds().left < enemy->sprite1.getGlobalBounds().left && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > enemy->sprite1.getGlobalBounds().top)
            {
                velocity.x=0.f;
                std::cout<<"right"<<std::endl;
                setPositionX(enemy->sprite1.getGlobalBounds().left - sprite.getGlobalBounds().width);
                setPositionY(sprite.getGlobalBounds().top);
            }
            if(sprite.getGlobalBounds().left > enemy->sprite1.getGlobalBounds().left && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > enemy->sprite1.getGlobalBounds().top)
            {
                velocity.x=0.f;
                std::cout<<"left"<<std::endl;
                setPositionX(enemy->sprite1.getGlobalBounds().left + 100.f);
                setPositionY(sprite.getGlobalBounds().top);
            }
            if(sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top && sprite.getGlobalBounds().top + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().left < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > enemy->sprite1.getGlobalBounds().left)
            {
                std::cout<<"kill"<<std::endl;
                setPositionX(sprite.getGlobalBounds().left);
                setPositionY(enemy->sprite1.getGlobalBounds().top - sprite.getGlobalBounds().height);
            }
        }

    }





}