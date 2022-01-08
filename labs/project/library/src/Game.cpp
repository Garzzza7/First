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

void Game::loadLevel(int levelId) {

}

