#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QSet>
#include <QTimer>

#include "gamescene.h"
#include "settings.h"
#include "game/game.h"

class GameController : public QObject
{
    Q_OBJECT
public:
    explicit GameController(GameScene *view, Settings *settings, QObject *parent = nullptr);
    ~GameController();

    void update();
    void handleInput();
    void handleKeyPress(QKeyEvent *event);
    void handleKeyRelease(QKeyEvent *event);
    QVector<GameObject *> getObjects();
    GameState getGameState();

signals:
    void backToMainMenu();

private slots:
    void onGameStarted();
    void onGameUpdateTimer();

private:
    GameScene *view_;
    Game *game_;
    QTimer timer_;
    Settings *settings_;

    void initializeGame();
    void cleanupGame();
};

#endif // GAMECONTROLLER_H
