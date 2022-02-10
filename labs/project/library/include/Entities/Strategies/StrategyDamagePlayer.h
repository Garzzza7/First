#ifndef OOPPROJECT_STRATEGYDAMAGEPLAYER_H
#define OOPPROJECT_STRATEGYDAMAGEPLAYER_H

#include "CollisionStrategy.h"

class StrategyDamagedPlayer : public CollisionStrategy{
public:
    void performCollisionStrategy(int damage) const override;
};

#endif //OOPPROJECT_STRATEGYDAMAGEPLAYER_H
