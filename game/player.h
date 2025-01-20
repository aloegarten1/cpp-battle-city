#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include "tankdriver.h"

class Player : public TankDriver
{

public:
    Player(Game *game) : TankDriver(game), commands_() {};
    void setCommand(int c);
    void unsetCommand(int c);
    void update();

private:
    QList<int> commands_;
    int getCommandIdx(int c);
};

#endif // PLAYER_H
