#include "gamescene.h"
#include "qevent.h"
#include <QGraphicsScene>

GameScene::GameScene(Settings* settings, QWidget *parent)
    : QGraphicsView(parent), m_game(new Game(new QGraphicsScene(this), settings, this)) {
    QGraphicsScene* scene = m_game->scene();
    setScene(scene);

    // Set up the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);  // Example size
    scene->setSceneRect(0, 0, 800, 600);
}

void GameScene::keyPressEvent(QKeyEvent *event) {
    switch (event->key()) {
    case Qt::Key_Left:
        m_game->movePlayerLeft();
        break;
    case Qt::Key_Right:
        m_game->movePlayerRight();
        break;
    case Qt::Key_Up:
        m_game->movePlayerUp();
        break;
    case Qt::Key_Down:
        m_game->movePlayerDown();
        break;
    default:
        QGraphicsView::keyPressEvent(event);
    }
}
