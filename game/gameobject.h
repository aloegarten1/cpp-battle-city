#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"

class GameObject
{

public:
    GameObject(Game *game, float x, float y, bool collide, bool destructable);
    ~GameObject() = default;

    virtual void update();
    bool collideable() { return collide_; }
    bool destructable() { return destructable_; }

    float x() { return x_; }
    float y() { return y_; }

    virtual QString skin() = 0;

protected:
    QGraphicsPixmapItem pixmap_;
    bool collide_;
    bool destructable_;
    float x_;
    float y_;

    Game *game_;

    int frame_;


private:
};

#endif // GAMEOBJECT_H
