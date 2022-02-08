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
    ResourceRegistry * objectRegistry = ResourceRegistry::GetInstance();

    this->player = new Player(300,300);
    texture.loadFromFile(objectRegistry->relativeTexturePath + "background.png");
    BG.setTexture(texture);
    BG.setPosition(-150.f,-250.f);
    BG.scale(0.45f,0.45f);
    hitbox.setPosition(0.f,0.f);
    hitbox.setSize(sf::Vector2(1600.f,432.f));
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setOutlineColor(sf::Color::White);
    hitbox.setOutlineThickness(1.f);



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

    this->window.create(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);

    this->view.zoom(0.33f);

    this->window.setFramerateLimit(60);
}

void Game::initLevels() {

    Level * level1 = new Level("level_1");

    levels.push_back(level1);
}

//Rendering code:
void Game::render() {
    this->window.clear();
    this->window.draw(BG);
    this->window.draw(hitbox);

    this->player->render(this->window);
    this->levels.at(0)->render(this->window);



    this->view.setCenter(this->player->getPos()-sf::Vector2f(0.0f,101.0f));
    if(player->getPos().x<165.f) view.setCenter(sf::Vector2(165.f,player->getPos().y-101.f));
    if(player->getPos().x>1435.f) view.setCenter(sf::Vector2(1435.f,player->getPos().y-101.f));
    if(player->getPos().y<200.f) view.setCenter(sf::Vector2(player->getPos().x,100.f));
    this->window.setView(view);

    this->window.display();
}

//Code that runs every frame of the game:
void Game::update() {

    this->pollEvents();

    //Passing on the update event.

    this->levels.at(currentLevel)->update();
    this->player->update(this->window);

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
void Game::screencollision() {
    //left
   // if(player->getPos().x<400.f) view.setCenter(sf::Vector2(400.f,player->getPos().y));
    //right
   // if(player->getPos().x<400.f) view.setCenter(sf::Vector2(400.f,player->getPos().y));
   // //top

}


