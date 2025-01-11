#include "gamescene.h"
#include "game.h"
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

void GameScene::onGameStarted(Game *game)
{

    m_game = game;

    // Add all items from the game to the scene
    for (auto item : m_game->items())
    {
        m_scene->addItem(item);
    }
}

void GameScene::initializeGame()
{
    m_game = new Game(m_settings, this);
    onGameStarted(m_game);
}

void GameScene::cleanupGame()
{
    if (m_game)
    {
        for (auto item : m_game->items())
        {
            m_scene->removeItem(item);
            delete item;
        }
        delete m_game;
    }

    delete m_scene;
}
