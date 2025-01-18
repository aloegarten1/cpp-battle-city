#pragma once

#include "qtimer.h"
#ifndef GAME_H
#define GAME_H

#include <QObject>
#include <QVector>
#include <QGraphicsItem>

#include "settings.h"

class Tank;
class Player;
class Enemy;
class GameObject;

class Game : public QObject
{
    Q_OBJECT

public:
    explicit Game(Settings *settings, QObject *parent = nullptr);
    ~Game();

    // game objects createion: player, enemies, walls, etc
    void init();

    // key down
    void setPlayerCommand(int c);
    // key up
    void unsetPlayerCommand(int c);

    GameObject *collide(GameObject *obj, float x, float y);

    void addGameObject(GameObject *obj);

signals:
    void gameObjectAdded(GameObject *obj);
    void gameObjectDestroyed(GameObject *obj);

private slots:
    void onGameUpdateTimer();

private:
    Settings *m_settings;
    Player *m_player;
    QTimer m_timer;

    QVector<GameObject *> m_items;
    QVector<Enemy *> m_enemies;

    void destroyGameObject(GameObject *obj);

    void parseTailset();
    void initializeMap();
    void initializePlayer();
    void initializeEnemies();

    void onTankKilled(Tank *tank);

    void popup(QString name);
    void loose();
    void win();
};

#endif // GAME_H
