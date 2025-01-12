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
    Tank(Game *game, int x, int y, int size) : GameObject(game, x,y,size), velocityX_(0), velocityY_(0) {}

    void setVelocity(int vx, int vy);
    void update() override;

private:
    int velocityX_;
    int velocityY_;

};

#endif // TANK_H
