#ifndef OOPPROJECT_GAME_H
#define OOPPROJECT_GAME_H

#include <vector>
#include <mutex>
#include "Level.h"

class Game{
    static Game * instance;
    static std::mutex mutex;
    std::vector<Level> levels;

protected:
    //The constructor and destructor are protected to prevent calls with "new/delete".
    Game(){};
    ~Game(){};
public:

    //Deletes the possibility to clone the game class.
    Game(Game &other) = delete;
    void operator=(const Game &) = delete;

    static Game * GetInstance();

    void loadLevel(int levelId), loadLevel(Level level);
    Level loadLevelsFolder();
    Level getLevelById(int levelId);
};

#endif //OOPPROJECT_GAME_H
