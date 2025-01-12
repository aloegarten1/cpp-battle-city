#pragma once


#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QGraphicsItem>

#include "settings.h"
#include "tileset.h"

class Player;
class GameObject;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(Settings *settings, QObject *parent = nullptr);

    TileSet *getTileset() {return &m_tileset; };

    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    void doPlayerShot();
    void stopPlayer();

    void update();
    bool collide(int x, int y);

    QVector<GameObject *> items() const;

signals:
    void gameUpdated();

private:
    Settings *m_settings;
    Player *m_player;

    TileSet m_tileset;

    QVector<GameObject *> m_items;

    void parseTailset();
    void initializeMap();
    void initializePlayer();
    void initializeEnemies();



};

#endif // GAME_H
