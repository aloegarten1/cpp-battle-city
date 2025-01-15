#pragma once

#ifndef TANKDRIVER_H
#define TANKDRIVER_H

#include "tank.h"
class TankDriver
{

public:
    TankDriver(Game *game);
    void initTank(QString tile, float x, float y);
    Tank *getTank();

protected:
    Tank *tank_;
    Game *game_;
};

#endif // TANKDRIVER_H
