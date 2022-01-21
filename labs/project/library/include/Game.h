#ifndef OOPPROJECT_GAME_H
#define OOPPROJECT_GAME_H

#include <vector>
#include <mutex>
#include <SFML/Graphics.hpp>
#include "Level.h"
#include "Player.h"

class Game{

    //Static singleton variables:
    static Game * instance;
    static std::mutex mutex;




    //The rest of variables:

    Player * player;

    bool running;

    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::View view {sf::Vector2f(0.0f,0.0f),sf::Vector2f(512.0f,512.0f)};

    std::vector<Level*> levels;

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

    void update();
    void render();

    void pollEvents();

    void initWindow();
    void initLevels();

    bool isRunning();

    sf::RenderWindow getWindow();

    void addLevel(Level level);
    void loadLevel(int levelId);
    void loadLevel(Level level);
    Level loadLevelsFolder();
};

#endif //OOPPROJECT_GAME_H
