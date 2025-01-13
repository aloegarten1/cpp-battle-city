#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "game.h"
#include "gameobjectm.h"


class Projectile  : public GameObjectM
{
public:
    Projectile(Game *game, float x, float y) :
        GameObjectM(game, x,y,false,false)  {
        velocity_ = 0.4;
    }

protected:

    QString skin() override;


};


#endif // PROJECTILE_H
