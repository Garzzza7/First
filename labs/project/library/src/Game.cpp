//
// Created by specklew on 08.01.2022.
//

#include "Game.h"

//Definitions of static classes.
Game * Game::instance{nullptr};
std::mutex Game::mutex;

//Locking the storage location using lock_guard.
Game * Game::GetInstance() {
    std::lock_guard<std::mutex> lock(mutex);
    if(instance == nullptr){
        instance = new Game();
    }
    return  instance;
}

Game::Game() {
    this->player = new Player();

    initWindow();
    running = true;
}

Game::~Game() {
    delete this->player;
}

void Game::initWindow() {

    this->videoMode.height = 800;
    this->videoMode.width = 1000;

    this->window.create(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);

    this->window.setFramerateLimit(60);
}

//Rendering code:
void Game::render() {
    this->window.clear(sf::Color::Blue);

    this->player->render(this->window);

    this->window.display();
}

//Code that runs every frame of the game:
void Game::update() {

    this->pollEvents();

    //Passing on the update event.
    this->player->update();

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
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::loadLevel(int levelId) {

}

