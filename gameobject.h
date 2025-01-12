#pragma once

#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>
#include "game.h"

class GameObject: public QGraphicsPixmapItem
{

public:
    GameObject(Game * game, int x, int y, int size);
    ~GameObject() = default;
    void SetTile(QString name);
    virtual void update() = 0;

protected:

    int x_;
    int y_;

    int width_;
    int height_;

    Game * game_;

};

#endif // GAMEOBJECT_H
