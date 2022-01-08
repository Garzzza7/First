#ifndef OOPPROJECT_GAME_H
#define OOPPROJECT_GAME_H

#include <vector>
#include <mutex>
#include <SFML/Graphics.hpp>
#include "Level.h"

class Game{

    //Static singleton variables:
    static Game * instance;
    static std::mutex mutex;

    //The rest of variables:
    bool running;

    sf::RenderWindow * window;
    sf::VideoMode videoMode;
    sf::Event ev;

    std::vector<Level> levels;

protected:
    //The constructor and destructor are protected to prevent calls with "new/delete".
    Game();
    ~Game();
public:

    //Singleton functionality.
    //Deletes the possibility to clone the game class.
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;

    static Game * GetInstance();

    //Game functions:

    void Update();
    void Render();

    void pollEvents();

    void initWindow();

    bool isRunning();

    void loadLevel(int levelId);
    void loadLevel(Level level);
    Level loadLevelsFolder();
    Level getLevelById(int levelId);
};

#endif //OOPPROJECT_GAME_H
