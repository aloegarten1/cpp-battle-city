#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QGraphicsScene>
#include "settings.h"
#include "player.h"

class Game : public QObject {
    Q_OBJECT

public:
    explicit Game(QGraphicsScene* scene, Settings* settings, QObject *parent = nullptr);

    void initializeEnemies();
    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();

    QGraphicsScene* scene(){ return m_scene;}

private:
    QGraphicsScene* m_scene;
    Settings* m_settings;
    Player* m_player;

    void initializePlayer();

};

#endif // GAME_H
