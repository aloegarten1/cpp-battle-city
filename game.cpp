#include "game.h"
#include "enemy.h"
#include "tank.h"
#include "player.h"
#include <QRandomGenerator>

Game::Game(Settings *settings, QObject *parent)
    : QObject(parent), m_settings(settings), m_player(nullptr),m_tileset(TileSet(QString(":/images/images/tanks.png")))
{
    parseTailset();
    initializePlayer();
    initializeEnemies();
}

void Game::parseTailset(){
    m_tileset.addTile("player1",QRect(2.0f, 2.0f, 15.0f, 15.0f));
}

void Game::initializeEnemies()
{
    int enemiesCount = m_settings->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i)
    {
        Enemy *enemy = new Enemy();
        // Place enemies at random positions within the scene
        int x = QRandomGenerator::global()->bounded(760); // 800 - 40 (enemy width)
        int y = QRandomGenerator::global()->bounded(560); // 600 - 40 (enemy height)
        enemy->setPos(x, y);
        m_items.append(enemy);
    }
}

void Game::initializePlayer()
{
    Tank * tank = new Tank(this, 400,300, 50);
    m_player = new Player(tank); // No need to pass scene here
//    m_player->setPos(400, 300);
    m_items.append(tank);
}

QVector<QGraphicsItem *> Game::items() const
{
    return m_items;
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
