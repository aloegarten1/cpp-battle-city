#ifndef WALL_H
#define WALL_H


#include "game.h"
#include "gameobject.h"

class Wall: public GameObject
{
public:
    Wall(Game *game, int x, int y) : GameObject(game, x,y, true, true) {

    }

 //   void update() override;

protected:
    QString skin() override;
};

#endif // WALL_H
