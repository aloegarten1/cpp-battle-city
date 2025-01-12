#ifndef WALL_H
#define WALL_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "game.h"
#include "gameobject.h"

class Wall: public GameObject
{
public:
    Wall(Game *game, int x, int y) : GameObject(game, x,y, true) {
        SetTile("wall");
    }

    void update() override;
};

#endif // WALL_H
