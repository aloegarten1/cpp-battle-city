#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"

class GameObject: public QGraphicsPixmapItem
{

public:
    GameObject(Game * game, float x, float y, bool collide, bool destructable);
    ~GameObject() = default;

    virtual void update() = 0;
    bool collideable() {return collide_;}
    bool destructable() {return destructable_;}



    float x() {return x_;}
    float y(){return y_;}
    void SetTile();

protected:

    bool collide_;
    bool destructable_;
    float x_;
    float y_;

    Game * game_;

    virtual QString skin() = 0;

private:



};

#endif // GAMEOBJECT_H
