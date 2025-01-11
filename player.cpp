#include "player.h"
#include <QKeyEvent>
#include <QGraphicsScene>

Player::Player(QGraphicsScene* scene, QObject *parent)
    : QObject(parent), QGraphicsRectItem(), m_scene(scene) {
    setRect(0, 0, 50, 50);
    setBrush(Qt::blue);  // Set the color of the player's tank

    // Add the player to the scene
    m_scene->addItem(this);
}

void Player::moveLeft() {
    if (pos().x() > 0) {
        setPos(x() - 10, y());
    }
}

void Player::moveRight() {
    if (pos().x() + rect().width() < m_scene->width()) {
        setPos(x() + 10, y());
    }
}

void Player::moveUp() {
    if (pos().y() > 0) {
        setPos(x(), y() - 10);
    }
}

void Player::moveDown() {
    if (pos().y() + rect().height() < m_scene->height()) {
        setPos(x(), y() + 10);
    }
}

void Player::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
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
