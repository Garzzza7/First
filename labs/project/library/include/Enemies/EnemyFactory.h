#ifndef OOPPROJECT_ENEMYFACTORY_H
#define OOPPROJECT_ENEMYFACTORY_H

#include "Resources/ResourceRegistry.h"
#include "Enemies/Enemy.h"
#include "Enemies/Goomba.h"
#include "Enemies/PPlant.h"
#include "Enemies/Coin.h"

class EnemyFactory{

    ResourceRegistry * resourceRegistry;

public:
    EnemyFactory();
    ~EnemyFactory(){};

    Enemy * CreateEnemy(unsigned int id);
};

#endif //OOPPROJECT_ENEMYFACTORY_H
