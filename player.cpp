#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::moveLeft()
{
    tank_->setDirecton(-1,0);
}

void Player::moveRight()
{
    tank_->setDirecton(1,0);
}
void Player::moveUp()
{
    tank_->setDirecton(0,-1);
}

void Player::moveDown()
{
    tank_->setDirecton(0,1);
}


void Player::stop()
{
    tank_->setDirecton(0,0);
}
