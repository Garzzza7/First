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
    initWindow();
    running = true;
}

Game::~Game() {
    delete this->window;
    delete this->instance;
}

void Game::initWindow() {

    this->videoMode.height = 600;
    this->videoMode.width = 800;

    this->window = new sf::RenderWindow(this->videoMode, "SFML Window", sf::Style::Titlebar | sf::Style::Close);

    this->window->setFramerateLimit(60);
}

void Game::Render() {
    this->window->clear(sf::Color::Cyan);
    this->window->display();
}

//Code that runs every frame of the game:
void Game::Update() {

    this->pollEvents();

    if(!this->window->isOpen()){
        running = false;
    }
}

//Event polling
void Game::pollEvents() {

    while (this->window->pollEvent(this->ev))
    {
        switch (this->ev.type)
        {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->ev.key.code == sf::Keyboard::Escape)
                    this->window->close();
                break;
        }
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::loadLevel(int levelId) {

}

