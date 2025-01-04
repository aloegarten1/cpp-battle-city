#include "game.h"
#include "gameobject.h"
#include "tileset.h"

#include <QTimer>
#include <QKeyEvent>

Game::Game(QObject *parent)
    : QGraphicsScene(parent)
{

    TileSet tl = TileSet(":/sheets/tanks.png");
    tl.addTile("tank1", QRect(2.0f, 2.0f, 15.0f, 15.0f));

    obj = new GameObject(tl.getTile("tank1"));

    addItem(obj);

    QTimer *_timer = new QTimer;

    connect(_timer, &QTimer::timeout, this, &Game::updateScene);

    _timer->start(16);

}

void Game::updateScene() {
    update();
}

void Game::keyPressEvent(QKeyEvent *keyEvent) {
    switch (keyEvent->key()) {
    case Qt::Key_Up:
        obj->moveBy(0.0f, -2.0f);
        break;
    case Qt::Key_Down:
        obj->moveBy(0.0f, 2.0f);
        break;
    }
}
