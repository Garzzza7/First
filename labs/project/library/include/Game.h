#ifndef OOPPROJECT_GAME_H
#define OOPPROJECT_GAME_H

#include <vector>
#include "Level.h"

class Game{
    std::vector<Level> levels;
public:
    void loadLevel(int levelId), loadLevel(Level level);
    Level loadLevelsFolder();
    Level getLevelById(int levelId);
};

#endif //OOPPROJECT_GAME_H
