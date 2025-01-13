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
    ~Game();

    void init();
    void update();

    TileSet *getTileset() {return &m_tileset; };

    void movePlayerLeft();
    void movePlayerRight();
    void movePlayerUp();
    void movePlayerDown();
    void doPlayerShot();
    void stopPlayer();


    GameObject * collide(GameObject * obj, float x, float y);


    // scale factor. virtual to real coordinates;
    float scale();

   // QVector<GameObject *> items() const;

 signals:
     void gameObjectAdded(GameObject * obj);
     void gameObjectDestroyed(GameObject * obj);

private:
    Settings *m_settings;
    Player *m_player;

    TileSet m_tileset;

    QVector<GameObject *> m_items;

    void addGameObject(GameObject * obj);
    void destroyGameObject(GameObject * obj);


    void parseTailset();
    void initializeMap();
    void initializePlayer();
    void initializeEnemies();



};

#endif // GAME_H
