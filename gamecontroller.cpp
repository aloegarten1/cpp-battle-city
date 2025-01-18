#include "gamecontroller.h"

GameController::GameController(GameScene *view, Settings *settings, QObject *parent)
    : QObject(parent)
{
    view_ = view;
    settings_ = settings;
    game_ = new Game(settings_);
    game_->init();
    emit onGameStarted();
}

GameController::~GameController()
{
    delete game_;
}
void GameController::handleKeyPress(QKeyEvent *event)
{

    switch (event->key())
    {
    case Qt::Key_P:
    {
        // TODO pause
        break;
    }
    case Qt::Key_Escape:
    {
        timer_.stop();
        emit backToMainMenu();
        break;
    }
    case Qt::Key_Left:
    case Qt::Key_Right:
    case Qt::Key_Up:
    case Qt::Key_Down:
    case Qt::Key_Space:
    {
        game_->setPlayerCommand(event->key());
        break;
    }
    }
}

void GameController::handleKeyRelease(QKeyEvent *event)
{
    game_->unsetPlayerCommand(event->key());
}

QVector<GameObject *> GameController::getObjects()
{
    return game_->getObjects();
}

void GameController::onGameStarted()
{

    connect(&timer_, &QTimer::timeout, this, &GameController::onGameUpdateTimer);
    timer_.start(50); // Update every x milliseconds
}

void GameController::onGameUpdateTimer()
{
    game_->update();
    view_->update();
}

GameState GameController::getGameState() { return game_->getState(); }
