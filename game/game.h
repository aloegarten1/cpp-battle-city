#pragma once

#ifndef GAME_H
#define GAME_H

#include "settings.h"

class Tank;
class Player;
class Enemy;
class GameObject;

enum class GameState
{
    RUNNING,
    PAUSED, // TODO
    WIN,
    LOOSE,
};

class Game
{

public:
    explicit Game(Settings *settings);
    ~Game();

    void init();

    GameState getState() { return state_; }
    void setState(GameState state);
    QVector<GameObject *> getObjects() { return items_; }

    // key down
    void setPlayerCommand(int c);
    // key up
    void unsetPlayerCommand(int c);

    void update();

    GameObject *collide(GameObject *obj, float x, float y);

    void addGameObject(GameObject *obj);

private:
    GameState state_;
    Settings *settings_;
    Player *player_;

    QVector<GameObject *> items_;
    QVector<GameObject *> destroyQueue_;
    QVector<Enemy *> enemies_;

    void destroyGameObject(GameObject *obj);

    void parseTileset();
    void initializeMap();
    void initializePlayer();
    void initializeEnemies();

    void onTankKilled(Tank *tank);

    void loose();
    void win();
};

#endif // GAME_H
