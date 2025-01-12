#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"

class GameObject: public QGraphicsPixmapItem
{

public:
    GameObject(Game * game, float x, float y, bool collide);
    ~GameObject() = default;

    void SetTile(QString name);
    virtual void update() = 0;
    bool collideable() {return collide_;}
    float x() {return x_;}
    float y(){return y_;}


protected:

    bool collide_;
    float x_;
    float y_;

    Game * game_;

};

#endif // GAMEOBJECT_H
