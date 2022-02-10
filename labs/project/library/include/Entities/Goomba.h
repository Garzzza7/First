#ifndef OOPPROJECT_GOOMBA_H
#define OOPPROJECT_GOOMBA_H

#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Entities/Strategies/StrategyDamagePlayer.h"
#include <ctime>

//template<class T>
class Goomba : public Entity{
protected:
    int hp{1};
    int damage{1};
    float acceleration{6};
    int id{4};

public:
    Goomba(Resource * base);

    ~Goomba();

    void updatePhysics() override ;
    void updateMovement() override;

    void move(const float dir_x,const float dir_y) override;

};

#endif //OOPPROJECT_GOOMBA_H
