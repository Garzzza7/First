#include "Player.h"
#include "Game.h"

Player::Player(int x , int y) : gif("../../textures/Mario.gif"){
 this->x=x;
 this->y=y;
    if(!this->standingTexture.loadFromFile("../../textures/MarioStanding.png")){
        throw std::runtime_error("Could not load texture mario standing texture.");
    }
    if(!this->jumpingTexture.loadFromFile("../../textures/MarioJumping.png")){
        throw std::runtime_error("Could not load texture mario jumping texture.");
    }
    this->sprite.setTexture(this->standingTexture);
    this->sprite.setTextureRect({0, 0, (int)this->standingTexture.getSize().x, (int)this->standingTexture.getSize().y});
    this->sprite.setPosition((float)x,(float)y);
    this->sprite.setOrigin((float)this->sprite.getTextureRect().width/2, (float)this->sprite.getTextureRect().height);
}

Player::~Player() {
    //TODO: Player destructor.
    std::cout<<"The player destructor is not defined!";
}

void Player::move(const float dir_x) {

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

void Player::update(sf::RenderTarget & target){

    this->updatePhysics();
    this->updateMovement();

    this->updateAnimations();
}

void Player::updatePhysics() {

    this->enemyCollisions();
    this->checkCollisions();

    velocity.y += gravity/100;
    this->sprite.move(velocity);
}

void Player::updateMovement() {
    if(goingLeft)
    {
        this->move(-1);
    }
    else if(goingRight)
    {
        this->move(1);
    }
    else{
        this->velocity.x=0;;
    }

    if(goingToJump && (onGround || jumpCount < 2)){
            this->jump(0,-1);
            jumpCount += 1; //TODO: make holding the key "W" down count as a single input.
            goingToJump = false;
    }
}

void Player::updateAnimations() {
    if(std::abs(this->velocity.x) > 0.1f && onGround) {
        this->gif.update(this->sprite);
    }
}

void Player::catchEvents(sf::Event event) {
    switch (event.type) {
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
                case sf::Keyboard::Key::D:
                    goingRight = true;
                    if(onGround) changeToGif(true);
                    break;

                case sf::Keyboard::Key::A:
                    goingLeft = true;
                    if(onGround) changeToGif(false);
                    break;

                case sf::Keyboard::Key::W:
                case sf::Keyboard::Key::Space:
                    goingToJump = true;
                    break;

                default:

                    break;
            }
            break;

        case sf::Event::KeyReleased:
            switch (event.key.code)
            {
                case sf::Keyboard::Key::D:
                    goingRight = false;
                    break;

                case sf::Keyboard::Key::A:
                    goingLeft = false;
                    break;
            }
            break;
    }
}

void Player::render(sf::RenderTarget & target) {
    target.draw(this->sprite);
}

sf::FloatRect Player::getPlayerBounds() {
    return this->sprite.getGlobalBounds();
}

#pragma region Private_Methods

void Player::setPositionX(float pos_x) {
    this->sprite.setPosition(pos_x, this->sprite.getPosition().y);
}

void Player::setPositionY(float pos_y) {
    this->sprite.setPosition(this->sprite.getPosition().x, pos_y);
}



void Player::changeToStandingTexture() {
    this->sprite.setTextureRect({0, 0, (int)this->standingTexture.getSize().x, (int)this->standingTexture.getSize().y});
    this->sprite.setTexture(this->standingTexture);
}

void Player::changeToJumpingTexture(bool moveDirection) {
    this->sprite.setTextureRect({0, 0, (int)this->jumpingTexture.getSize().x, (int)this->jumpingTexture.getSize().y});
    this->sprite.setTexture(this->jumpingTexture);
    if(moveDirection) sprite.setScale(1,1);
    else sprite.setScale(-1,1);
}

void Player::changeToGif(bool moveDirection) {
    this->sprite.setTextureRect({0, 0, this->gif.getSize().x, this->gif.getSize().y});
    if(moveDirection) sprite.setScale(1,1);
    else sprite.setScale(-1,1);
}



void Player::setOnGround(bool isOnGround) {
    this->onGround = isOnGround;
    if(onGround){
        if(abs(this->velocity.x) > 0.2f)
            changeToGif(this->velocity.x > 0.0f);
        else
            changeToStandingTexture();
    }
    else{
        changeToJumpingTexture(this->velocity.x > 0.0f);
    }
}

#pragma endregion

//Collision stuff:

void Player::checkCollisions() {

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
                }
                else{
                    setPositionY(this->sprite.getPosition().y - intersectY - 0.1f);
                    if(intersectY > 0){
                        setOnGround(true);
                        jumpCount = 0;
                    }
                    velocity.y -= velocity.y;
                }

            }
            else if(std::abs(velocity.y) > 0.2f){
                setOnGround(false);
            }
        }
    }
}
int Player::getHP() {
    return playerHealth;
}
void Player::receiveDamage(unsigned int& hp) {
    hp-=1;
}

void Player::enemyCollisions() {
        Game * game = Game::GetInstance();
        Level * level = game->getCurrentLevel();


    for (auto  enemy : level->enemies)
    {
        long str1{(long) "0x555670ea4820"};
        sf::FloatRect playerBounds=getPlayerBounds();
        sf::FloatRect enemyBounds=enemy->getEnemyBounds();
        //if(enemyBounds.intersects(getPlayerBounds()))
        if(reinterpret_cast<long>(enemy->getBase())==str1)
        {
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
                    //playerHealth-=enemy->damage;
                    receiveDamage(playerHealth);
                    std::cout<<getHP()<<std::endl;
                    die();
                }
                if(sprite.getGlobalBounds().left > enemy->sprite1.getGlobalBounds().left - enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > enemy->sprite1.getGlobalBounds().top)
                {
                    velocity.x=0.f;
                    std::cout<<"left"<<std::endl;

                    setPositionX(enemy->sprite1.getGlobalBounds().left + 100.f);
                    setPositionY(sprite.getGlobalBounds().top);
                    //playerHealth-=enemy->damage;
                    receiveDamage(playerHealth);
                    std::cout<<getHP()<<std::endl;
                    die();
                }
                if(sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top && sprite.getGlobalBounds().top + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().left < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > enemy->sprite1.getGlobalBounds().left)
                {
                    std::cout<<"kill"<<std::endl;
                    setPositionX(sprite.getGlobalBounds().left);
                    setPositionY(enemy->sprite1.getGlobalBounds().top - sprite.getGlobalBounds().height);
                    //XD???
                    enemy->setPosition(10000.f,10000.f);
                }
            }
        }
        else //if (reinterpret_cast<long>(enemy->getBase())==reinterpret_cast<long>("0x555670ea6bd0"))
        {
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
                    //playerHealth-=enemy->damage;
                    receiveDamage(playerHealth);
                    std::cout<<getHP()<<std::endl;
                    die();
                }
                if(sprite.getGlobalBounds().left > enemy->sprite1.getGlobalBounds().left - enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().top + sprite.getGlobalBounds().height > enemy->sprite1.getGlobalBounds().top)
                {
                    velocity.x=0.f;
                    std::cout<<"left"<<std::endl;

                    setPositionX(enemy->sprite1.getGlobalBounds().left + 100.f);
                    setPositionY(sprite.getGlobalBounds().top);
                    //playerHealth-=enemy->damage;
                    receiveDamage(playerHealth);
                    std::cout<<getHP()<<std::endl;
                    die();
                }
                if(sprite.getGlobalBounds().top < enemy->sprite1.getGlobalBounds().top && sprite.getGlobalBounds().top + sprite.getGlobalBounds().width < enemy->sprite1.getGlobalBounds().top + enemy->sprite1.getGlobalBounds().height && sprite.getGlobalBounds().left < enemy->sprite1.getGlobalBounds().left + enemy->sprite1.getGlobalBounds().width && sprite.getGlobalBounds().left + sprite.getGlobalBounds().width > enemy->sprite1.getGlobalBounds().left)
                {
                    std::cout<<"kill"<<std::endl;
                    setPositionX(sprite.getGlobalBounds().left);
                    setPositionY(enemy->sprite1.getGlobalBounds().top - sprite.getGlobalBounds().height);
                    //XD???
                    receiveDamage(playerHealth);
                    die();
                }
            }
        }


    }
}
void Player::die() {
    if(getHP()==0){
        setPositionX(x);
        setPositionY(y);
        playerHealth+=5;
    }
}
