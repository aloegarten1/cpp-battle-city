#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "tankdriver.h"

class Player : public TankDriver
{

public:
    Player(Game *game) : TankDriver(game), commands_() {};
    void setCommand(int c);
    void unsetCommand(int c);

private:
    QList<int> commands_;
    int getCommandIdx(int c);
    void applyCommand();
};

#endif // PLAYER_H
