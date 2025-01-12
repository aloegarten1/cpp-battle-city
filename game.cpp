#include "game.h"
#include "gameobject.h"
#include "enemy.h"
#include "tank.h"
#include "wall.h"
#include "player.h"
#include <QRandomGenerator>

Game::Game(Settings *settings, QObject *parent)
    : QObject(parent), m_settings(settings), m_player(nullptr),m_tileset(TileSet(QString(":/images/images/tanks2.png")))
{
    parseTailset();
    initializeMap();
    initializePlayer();
    initializeEnemies();
}

void Game::parseTailset(){
    m_tileset.addTile("player1",QRect(0.0f, 72.0f, 16.0f, 16.0f));

    m_tileset.addTile("enemy1",QRect(0.0f, 0.0f, 16.0f, 16.0f));

    m_tileset.addTile("wall1",QRect(235.0f, 0.0f, 16.0f, 16.0f));

}

void Game::initializeEnemies()
{
    int enemiesCount = m_settings->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i)
    {

        int x = QRandomGenerator::global()->bounded(16);
        int y = QRandomGenerator::global()->bounded(12);

        Tank *enemy = new Tank(this, x*50, y*50, 50);
        enemy->SetTile("enemy");

        m_items.append(enemy);
    }
}

void Game::initializePlayer()
{
    Tank * tank = new Tank(this, 400,300, 50);
    tank->SetTile("player");
    m_player = new Player(tank);


//    m_player->setPos(400, 300);
    m_items.append(tank);
}

void  Game::initializeMap(){
    for (int i=0; i<16; i++){
        for (int j=0; j<12; j++){

            int g = QRandomGenerator::global()->bounded(100);

            if (g>25){
                continue;
            }

            Wall *wall = new Wall(this, i*50, j*50, 50);


            m_items.append(wall);

        }
    }
}


QVector<GameObject *> Game::items() const
{
    return m_items;
}

void Game::update() {
    for (auto item : m_items) {

        item->update();
       // Enemy* enemy = dynamic_cast<Enemy*>(item);

        // if (enemy) {
        //     enemy->move();
        // }

    }
    emit gameUpdated();
}


void Game::movePlayerLeft()
{
    m_player->moveLeft();
}

void Game::movePlayerRight()
{
    m_player->moveRight();
}

void Game::movePlayerUp()
{
    m_player->moveUp();
}

void Game::movePlayerDown()
{
    m_player->moveDown();
}

void Game::stopPlayer()
{
    m_player->stop();
}


void Game::doPlayerShot()
{
    // TODO
}


bool Game::collide(int x, int y){
    return false;
}
