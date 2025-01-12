#ifndef CONCRETEWALL_H
#define CONCRETEWALL_H
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "game.h"
#include "gameobject.h"
class ConcreteWall: public GameObject
{
public:
    ConcreteWall(Game *game, int x, int y) : GameObject(game, x,y, true) {
        SetTile("concreteWall");
    }

    void update() override;
};

#endif // CONCRETEWALL_H



