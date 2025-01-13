#pragma once

#ifndef TANK_H
#define TANK_H

#include "game.h"
#include "gameobjectm.h"



class Tank : public GameObjectM
{
public:
    Tank(Game *game, float x, float y,QString mark ) :
        GameObjectM(game, x,y, true, true),
        mark_(mark)    {}



protected:

    QString skin() override;

private:

    QString mark_;

};

#endif // TANK_H
