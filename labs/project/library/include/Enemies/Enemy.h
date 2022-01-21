#ifndef OOPPROJECT_ENEMY_H
#define OOPPROJECT_ENEMY_H

#include <SFML/Graphics.hpp>

class Enemy{
private:
    int hp;
    int damage;
    float movementSpeed;
protected:
    int id;
public:
    Enemy(string id);
    ~Enemy();
    update();
};


#endif //OOPPROJECT_ENEMY_H
