#pragma once

#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QGraphicsItem>

#include "settings.h"
#include "tileset.h"

class Player;

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

    QVector<QGraphicsItem *> items() const;

private:
    Settings *m_settings;
    Player *m_player;

    TileSet m_tileset;

    QVector<QGraphicsItem *> m_items;

    void parseTailset();
    void initializePlayer();
    void initializeEnemies();

};

#endif // GAME_H
