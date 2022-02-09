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
    int currentLevel{0};

    sf::RenderWindow window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::View view {sf::Vector2f(0.0f,0.0f),sf::Vector2f(1000.0f,800.0f)};
    sf::Texture texture;
    sf::Sprite BG;

    sf::RectangleShape hitbox;

    std::vector<Level*> levels;

    //Private methods:
    void applyCorrectScreenCenter();

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

    void screencollision();

    void pollEvents();

    void initWindow();
    void initLevels();

    bool isRunning();

    Level * getCurrentLevel();

    void collisionEnemy();
};

#endif //OOPPROJECT_GAME_H
