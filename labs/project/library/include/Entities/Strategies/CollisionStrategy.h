#ifndef OOPPROJECT_COLLISIONSTRATEGY_H
#define OOPPROJECT_COLLISIONSTRATEGY_H

#include "Player.h"

class CollisionStrategy{
public:
    virtual ~CollisionStrategy();
    virtual void performCollisionStrategy(int data) const = 0;
};

#endif //OOPPROJECT_COLLISIONSTRATEGY_H
