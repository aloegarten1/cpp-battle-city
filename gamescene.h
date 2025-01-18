#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>
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
    void paintEvent(QPaintEvent* event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private slots:
    void onGameStarted(Game *game);

private:
    void initializeGame();
    void cleanupGame();

    void drawObject(QPainter& painter, const QPointF& position, const QString& textureKey);

    Settings *m_settings;
    Game *m_game;
    QGraphicsScene *m_scene;

};

#endif // GAME_SCENE_H
