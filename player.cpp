#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::moveLeft()
{
    tank_->setVelocity(-1,0);
}

void Player::moveRight()
{
    tank_->setVelocity(1,0);
}
void Player::moveUp()
{
    tank_->setVelocity(0,-1);
}

void Player::moveDown()
{
    tank_->setVelocity(0,1);
}


void Player::stop()
{
    tank_->setVelocity(0,0);
}
