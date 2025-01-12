#pragma once

#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "game.h"
#include "gameobject.h"

enum class Direction : int{
    UP =1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

class Tank : public GameObject
{
public:
    Tank(Game *game, float x, float y,QString mark ) :
        GameObject(game, x,y,true),
        velocityX_(0),
        velocityY_(0),
        velocity_(0.2),
        mark_(mark),
        dir_(Direction::UP),
        sprite_(0),
        frame_(0)    {}

    void setDirecton(Direction dir);
    void stop();
    void update() override;

protected:

    QString skin() override;

private:
    float velocityX_;
    float velocityY_;
    float velocity_;
    QString mark_;
    Direction dir_;
    int sprite_;
    int frame_;
};

#endif // TANK_H
