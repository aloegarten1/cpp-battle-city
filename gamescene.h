#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>
#include "settings.h"

class GameScene : public QGraphicsView {
    Q_OBJECT

public:
    GameScene(Settings* settings, QWidget *parent = nullptr);


signals:
    void backToMainMenu();

private:
    void initializeEnemies();

    Settings* m_settings;
};

#endif // GAME_SCENE_H
