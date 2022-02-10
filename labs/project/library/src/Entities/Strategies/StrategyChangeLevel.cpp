#include "Entities/Strategies/StrategyChangeLevel.h"
#include "Game.h"

void StrategyChangeLevel::performCollisionStrategy(int levelId) const {
    Game * game = Game::GetInstance();
    game->changeLevel(levelId);
}
