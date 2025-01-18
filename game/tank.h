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

    void fire();


protected:

    QString skin() override;

private:

    QString mark_;

    int reloadCountdown_; // fire rate controll

};

#endif // TANK_H
