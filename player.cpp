#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::moveLeft()
{
    tank_->moveLeft();
}

void Player::moveRight()
{
    tank_->moveRight();
}
void Player::moveUp()
{
    tank_->moveUp();
}

void Player::moveDown()
{
    tank_->moveDown();
}
