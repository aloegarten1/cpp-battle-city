#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>
#include "settings.h"
#include "player.h"

class GameScene : public QGraphicsView {
    Q_OBJECT

public:
    GameScene(Settings* settings, QWidget *parent = nullptr);


signals:
    void backToMainMenu();

private:
    void initializeEnemies();
    void initializePlayer();

    void keyPressEvent(QKeyEvent *event) override;

    Settings* m_settings;
    Player* m_player;
};

#endif // GAME_SCENE_H
