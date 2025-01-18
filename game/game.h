#pragma once


#ifndef GAME_H
#define GAME_H



#include "settings.h"

class Tank;
class Player;
class Enemy;
class GameObject;

class Game
{


public:
    explicit Game(Settings *settings);
    ~Game();


    void init();

    QVector<GameObject *> getObjects() {return m_items; }

    // key down
    void setPlayerCommand(int c);
    // key up
    void unsetPlayerCommand(int c);

    GameObject *collide(GameObject *obj, float x, float y);

    void addGameObject(GameObject *obj);


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
