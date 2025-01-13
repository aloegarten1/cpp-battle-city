#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>
#include <QTimer>
#include "gameobject.h"
#include "settings.h"

class Game;

class GameScene : public QGraphicsView
{
    Q_OBJECT

public:
    GameScene(Settings *settings, QWidget *parent = nullptr);
    ~GameScene()
    {
        cleanupGame();
    }

signals:
    void backToMainMenu();

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void onGameStarted(Game *game);
    void onGameObjectCreated(GameObject *obj);
    void onGameObjectDestroyed(GameObject *obj);
    void onGameUpdateTimer();

private:
    void initializeGame();
    void cleanupGame();

    Settings *m_settings;
    Game *m_game;
    QGraphicsScene *m_scene;
    QTimer m_timer;
};

#endif // GAME_SCENE_H
