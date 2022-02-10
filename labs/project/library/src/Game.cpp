#include "Game.h"
#include "Resources/ResourceRegistry.h"

//Definitions of static classes.
Game * Game::instance{nullptr};
std::mutex Game::mutex;

//Locking the storage location using lock_guard.
Game * Game::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if(instance == nullptr){
        instance = new Game();
    }
    return instance;
}

Game::Game() {
    ResourceRegistry * resourceRegistry = ResourceRegistry::GetInstance();

    this->player = new Player(300,300);

    initWindow();
    initLevels();
    running = true;
}

Game::~Game() {
    delete this->player;
    for(auto level : levels){
        delete level;
    }
}

void Game::initWindow() {

    this->videoMode.height = 800;
    this->videoMode.width = 1000;

    this->window.create(this->videoMode, "Supa mario", sf::Style::Titlebar | sf::Style::Close);

    this->view.zoom(0.33f);

    this->window.setFramerateLimit(60);
}

void Game::initLevels() {

    auto * level1 = new Level("level_1");
    auto * level2 = new Level("level_2");
    auto * level3 = new Level("level_3");

    levels.push_back(level1);
    levels.push_back(level2);
    levels.push_back(level3);
}

//Rendering code:
void Game::render() {
    this->window.clear();

    this->levels.at(currentLevel)->render(this->window);
    this->player->render(this->window);

    //The screen is 21 blocks wide
    //and about 17 block tall.
    applyCorrectScreenCenter();

    this->window.setView(view);

    this->window.display();
}

void Game::applyCorrectScreenCenter() {
    ResourceRegistry * resourceRegistry = ResourceRegistry::GetInstance();
    const auto tileSize = (float)resourceRegistry->getTileSize();
    const auto levelLength = (float)levels.at(currentLevel)->getLevelLength();
    const auto levelHeight = (float)levels.at(currentLevel)->getLevelHeight();
    const float halfScreenHeight = 8.33f;
    const float halfScreenWidth = 10.33f;
    float screenX = (float)player->getPos().x;
    float screenY = (float)player->getPos().y;

    if(player->getPos().x < halfScreenWidth * tileSize){
        screenX = halfScreenWidth * tileSize;
    }

    if(player->getPos().x > (levelLength - halfScreenWidth) * tileSize){
        screenX = (levelLength - halfScreenWidth) * tileSize;
    }

    if(player->getPos().y < halfScreenHeight * tileSize){
        screenY = halfScreenHeight * tileSize;
    }

    if(player->getPos().y > (levelHeight - halfScreenHeight) * tileSize){
        screenY = (levelHeight - halfScreenHeight) * tileSize;
    }

    this->view.setCenter(screenX, screenY);
}

//Code that runs every frame of the game:
void Game::update() {

    this->pollEvents();

    //Passing on the update event.

    this->levels.at(currentLevel)->update();
    this->player->update(this->window);
    if(this->player->getPos().x > 640){
        //currentLevel = 1;

    }

    if(!this->window.isOpen()) running = false;

}

//Event polling
void Game::pollEvents() {

    while (this->window.pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window.close();
                running = false;
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape) {
                    this->window.close();
                    running = false;
                }
                break;
        }
        this->player->catchEvents(ev);
    }
}

bool Game::isRunning() {
    return this->running;
}

Level *Game::getCurrentLevel() {
    return levels.at(this->currentLevel);
}

void Game::changeLevel(int levelId) {
    currentLevel = levelId;
    this->player->setPlayerPosition(300,300);
}

void Game::screenCollision() {

}