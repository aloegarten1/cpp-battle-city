#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "tank.h"

class Player
{

public:
    Player(Tank * tank): tank_(tank) {};
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

    void stop();

    Tank * tank(){return tank_;}

private:
    Tank * tank_;
};

#endif // PLAYER_H
