#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include "settings.h"
#include "player.h"

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(Settings *settings, QObject *parent = nullptr);

    void initializeEnemies();

    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();

    QVector<QGraphicsItem *> items() const;

private:
    Settings *m_settings;
    Player *m_player;

    QVector<QGraphicsItem *> m_items;

    void initializePlayer();
};

#endif // GAME_H
