#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

void Player::moveLeft()
{

    setPos(x() - 10, y());
}

void Player::moveRight()
{

    setPos(x() + 10, y());
}

void Player::moveUp()
{

    setPos(x(), y() - 10);
}

void Player::moveDown()
{

    setPos(x(), y() + 10);
}

void Player::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Left:
        moveLeft();
        break;
    case Qt::Key_Right:
        moveRight();
        break;
    case Qt::Key_Up:
        moveUp();
        break;
    case Qt::Key_Down:
        moveDown();
        break;
    default:
        QGraphicsRectItem::keyPressEvent(event);
    }
}
