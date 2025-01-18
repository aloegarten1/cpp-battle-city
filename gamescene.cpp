#include "gamescene.h"
#include "game/game.h"
#include "game/gameobject.h"
#include "qevent.h"
#include "tileset.h"
#include <QGraphicsScene>

GameScene::GameScene(Settings *settings, QWidget *parent)
    : QGraphicsView(parent), m_settings(settings), m_game(nullptr)
{

    m_scene = new QGraphicsScene(this);
    setScene(m_scene);

    initializeGame();

    // Set up the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    m_scene->setSceneRect(0, 0, 800, 600);

}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if (m_game == nullptr)
    {
        return;
    }
    switch (event->key())
    {
    case Qt::Key_Escape:
        emit backToMainMenu();
        break;

    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Space:
    {
        m_game->setPlayerCommand(event->key());
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
        m_game->unsetPlayerCommand(event->key());
        break;
    }
    default:
    {
        QGraphicsView::keyReleaseEvent(event);
        break;
    }
    }
}

void GameScene::onGameStarted(Game *game)
{
    m_game = game;
}


void GameScene::initializeGame()
{
    m_game = new Game(m_settings, this);
    m_game->init();
    onGameStarted(m_game);
}

void GameScene::cleanupGame()
{
    if (m_game)
    {

        delete m_game;
    }

    delete m_scene;
}





void GameScene::paintEvent(QPaintEvent* event) {

    QGraphicsView::paintEvent(event);
    QPainter painter(viewport());

    TileSet * tl = TileSet::getInstance();
    float scale = tl->scale();
    for (GameObject * obj : m_game->getObjects()) {

        QPointF position = QPointF(obj->x()*scale,obj->y()*scale);
        QString textureKey = obj->skin();
        const QPixmap& pixmap = tl->getTile(textureKey);
        painter.drawPixmap(position.x(), position.y(), pixmap.scaled(scale,scale));

    }

}
