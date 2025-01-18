#ifndef ENEMYHQ_H
#define ENEMYHQ_H

#include "game.h"
#include "gameobject.h"

class EnemyHQ : public GameObject
{
public:
    EnemyHQ(Game *game, int x, int y) : GameObject(game, x, y, true, true) {};

protected:
    QString skin() override;
};

#endif // ENEMYHQ_H
