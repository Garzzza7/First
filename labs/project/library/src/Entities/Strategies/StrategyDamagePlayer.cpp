#include "Entities/Strategies/StrategyDamagePlayer.h"
#include "Game.h"

void StrategyDamagedPlayer::performCollisionStrategy(int damage) const {
    Game * game = Game::GetInstance();
    game->player->receiveDamage(damage);
}
