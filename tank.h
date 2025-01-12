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
    Tank(Game *game, float x, float y ) : GameObject(game, x,y,true), velocityX_(0), velocityY_(0),velocity_(0.2) {}

    void setDirecton(float vx, float vy);
    void update() override;

private:
    float velocityX_;
    float velocityY_;
    float velocity_;

};

#endif // TANK_H
