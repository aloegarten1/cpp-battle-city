#include "gamescene.h"
#include "game/game.h"
#include "game/gameobject.h"
#include "gamecontroller.h"
#include "qevent.h"
#include "tileset.h"
#include <QGraphicsScene>

GameScene::GameScene(QWidget *parent)
    : QGraphicsView(parent)
{
    controller_ = nullptr;

    scene_ = new QGraphicsScene(this);
    setScene(scene_);

    // Set up the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    scene_->setSceneRect(0, 0, 800, 600);
}

void GameScene::setController(GameController *controller)
{
    controller_ = controller;
}

void GameScene::keyPressEvent(QKeyEvent *event)
{

    switch (event->key())
    {
    case Qt::Key_P:
    case Qt::Key_Escape:
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Space:
    {
        if (controller_ == nullptr)
        {
            return;
        }
        controller_->handleKeyPress(event);
        break;
    }

    default:
        QGraphicsView::keyPressEvent(event);
    }
}

void GameScene::keyReleaseEvent(QKeyEvent *event)
{

    switch (event->key())
    {
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Space:
    {
        if (controller_ == nullptr)
        {
            return;
        }
        controller_->handleKeyRelease(event);
        break;
    }
    default:
    {
        QGraphicsView::keyReleaseEvent(event);
        break;
    }
    }
}

void GameScene::update()
{

    viewport()->update();
}

void GameScene::paintEvent(QPaintEvent *event)
{

    QGraphicsView::paintEvent(event);

    if (controller_ == nullptr)
    {
        return;
    }

    QPainter painter(viewport());

    GameState state = controller_->getGameState();

    TileSet *tl = TileSet::getInstance();
    float scale = tl->scale();

    switch (state)
    {
    case GameState::RUNNING:
    {
        for (GameObject *obj : controller_->getObjects())
        {
            QPointF position = QPointF(obj->x() * scale, obj->y() * scale);
            QString textureKey = obj->skin();
            const QPixmap &pixmap = tl->getTile(textureKey);
            painter.drawPixmap(position.x(), position.y(), pixmap.scaled(scale, scale));
        }

        break;
    }
    case GameState::PAUSED:
    {
        const QPixmap &pixmap = tl->getTile("pause");
        painter.drawPixmap(336, 264, pixmap);
        break;
    }
    case GameState::WIN:
    {
        const QPixmap &pixmap = tl->getTile("win");
        painter.drawPixmap(336, 264, pixmap);
        break;
    }
    case GameState::LOOSE:
    {
        const QPixmap &pixmap = tl->getTile("loose");
        painter.drawPixmap(336, 264, pixmap);
        break;
    }
    }
}
