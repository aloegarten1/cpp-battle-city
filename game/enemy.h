#ifndef ENEMY_H
#define ENEMY_H

#include "tankdriver.h"

class Enemy : public TankDriver
{

public:
    Enemy(Game *game) : TankDriver(game) {}

    void AI();

private:
    int frame_;
};
#endif // ENEMY_H
