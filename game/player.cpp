#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::setCommand(int c)
{
    if (!alive_) return;

    if (getCommandIdx(c) >= 0)
    {
        return;
    }
    commands_.append(c);
    applyCommand();
}

void Player::unsetCommand(int c)
{
    if (!alive_) return;

    int idx = getCommandIdx(c);
    if (idx < 0)
    {
        return;
    }
    commands_.removeAt(idx);
    applyCommand();
}

void Player::applyCommand()
{
    if (!alive_) return;

    bool move = false;
    Direction dir;

    for (int i = 0; i < commands_.length(); i++)
    {
        int c = commands_.at(i);

        switch (c)
        {
        case Qt::Key_Left:
            move = true;
            dir = Direction::LEFT;
            break;
        case Qt::Key_Right:
            move = true;
            dir = Direction::RIGHT;
            break;
        case Qt::Key_Up:
            move = true;
            dir = Direction::UP;
            break;
        case Qt::Key_Down:
            move = true;
            dir = Direction::DOWN;
            break;
        case Qt::Key_Space:
            tank_->fire();
            break;
        }
    }

    if (!move)
    {
        tank_->stop();
        return;
    }

    tank_->setDirecton(dir);
}

int Player::getCommandIdx(int c)
{

    for (int i = 0; i < commands_.length(); i++)
    {
        if (commands_.at(i) == c)
        {
            return i;
        }
    }
    return -1;
}
