#include "game.h"
#include "concretewall.h"
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

float Game::scale(){
    // hardcoded
    return 48.;
}

void Game::parseTailset(){
    m_tileset.addTile("player1",QRect(0.0f, 72.0f, 16.0f, 16.0f));

    m_tileset.addTile("enemy1",QRect(0.0f, 0.0f, 16.0f, 16.0f));

    m_tileset.addTile("wall1",QRect(235.0f, 0.0f, 16.0f, 16.0f));

    m_tileset.addTile("concreteWall1",QRect(267.0f, 48.0f, 16.0f, 16.0f));


}

void Game::initializeEnemies()
{
    int enemiesCount = m_settings->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i)
    {

        int x = QRandomGenerator::global()->bounded(16);
        int y = QRandomGenerator::global()->bounded(12);

        Tank *enemy = new Tank(this, x, y);
        enemy->SetTile("enemy");

        m_items.append(enemy);
    }
}

void Game::initializePlayer()
{
    Tank * tank = new Tank(this, 1,10);
    tank->SetTile("player");
    m_player = new Player(tank);

    m_items.append(tank);
}

void  Game::initializeMap(){

    for (int ix=0; ix<16; ix++){

        ConcreteWall *cwall = new ConcreteWall(this, ix, 0);
        m_items.append(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, ix, 11);
        m_items.append(cwall2);


        for (int jy=1; jy<11; jy++){

            if (ix==1 && jy==10){
                continue;
            }

            int g = QRandomGenerator::global()->bounded(100);

            if (g>25){
                continue;
            }

            Wall *wall = new Wall(this, ix, jy);
            m_items.append(wall);

        }
    }

    for (int j=1; j<11; j++){
        ConcreteWall *cwall = new ConcreteWall(this, 0, j);
        m_items.append(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, 15, j);
        m_items.append(cwall2);

    }
}


QVector<GameObject *> Game::items() const
{
    return m_items;
}

void Game::update() {
    for (auto item : m_items) {

        item->update();
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


GameObject * Game::collide(GameObject * obj, float x, float y){

    for (GameObject * item: m_items){
        if (obj == item || !item->collideable()){
            continue;
        }



        // int left1 = x*scale();
        // int right1 = (x + 1.)*scale();
        // int left2 = (item->x())*scale();
        // int right2 = (item->x() + 1.)*scale();
        // int top1 = y*scale();
        // int bottom1 = (y + 1.)*scale();
        // int top2 = (item->y() + 1.)*scale();
        // int bottom2 = (item->y() + 1.)*scale();

        // bool collided =  !(right1 < left2 ||      // r1.right < r2.left
        //                   left1 > right2 ||               // r1.left > r2.right
        //                   bottom1 > top2 ||      // r1.bottom > r2.top
        //                   top1 < bottom2);               // r1.top < r2.bottom

        bool collided = std::abs(x-item->x())<1 && std::abs(y-item->y())<0.8;

        if (collided){
            return item;
        }
    }

    return nullptr;
}
