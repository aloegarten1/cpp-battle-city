#pragma once

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

    void init();
    void update();

    void setPlayerCommand(int c);
    void unsetPlayerCommand(int c);

    GameObject *collide(GameObject *obj, float x, float y);

    float scale();

    void addGameObject(GameObject *obj);

signals:
    void gameObjectAdded(QGraphicsPixmapItem *obj);
    void gameObjectDestroyed(GameObject *obj);

private:
    Settings *m_settings;
    Player *m_player;

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
