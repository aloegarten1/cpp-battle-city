#include "gamescene.h"
#include "game.h"
#include "gameobject.h"
#include "qevent.h"
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

    connect(&m_timer, &QTimer::timeout, this, &GameScene::onGameUpdateTimer);
    m_timer.start(50); // Update every x milliseconds
}

void GameScene::onGameUpdateTimer()
{
    if (m_game)
    {
        m_game->update();
    }
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
        backToMainMenu();
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
        m_game->unsetPlayerCommand(event->key());
    default:
        QGraphicsView::keyReleaseEvent(event);
    }
}

void GameScene::onGameStarted(Game *game)
{

    m_game = game;

    // for (GameObject * item : m_game->items())
    // {
    //     m_scene->addItem(item);
    // }
}

void GameScene::onGameObjectCreated(GameObject *obj)
{
    m_scene->addItem(obj);
}

void GameScene::onGameObjectDestroyed(GameObject *obj)
{
    m_scene->removeItem(obj);
}

void GameScene::initializeGame()
{
    m_game = new Game(m_settings, this);
    connect(m_game, &Game::gameObjectAdded, this, &GameScene::onGameObjectCreated);
    connect(m_game, &Game::gameObjectDestroyed, this, &GameScene::onGameObjectDestroyed);
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
