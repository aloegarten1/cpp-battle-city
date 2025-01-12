#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::moveLeft()
{

    tank_->setDirecton(Direction::LEFT);
}

void Player::moveRight()
{
    tank_->setDirecton(Direction::RIGHT);
}
void Player::moveUp()
{
    tank_->setDirecton(Direction::UP);
}

void Player::moveDown()
{
    tank_->setDirecton(Direction::DOWN);
}


void Player::stop()
{
    tank_->stop();
}
