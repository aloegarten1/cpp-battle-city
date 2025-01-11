#pragma once

#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "game.h"
#include "gameobject.h"


class Tank : public GameObject
{
public:
    Tank(Game *game, int x, int y, int size) : GameObject(game, x,y,size) {

        auto tl =  game->getTileset();
        QPixmap img = tl->getTile("player1");
        setPixmap(img.scaled(QSize(50,50),Qt::KeepAspectRatio));

    }

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

};

#endif // TANK_H
