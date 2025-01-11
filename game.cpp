#include "game.h"
#include "enemy.h"
#include <QRandomGenerator>

Game::Game(Settings *settings, QObject *parent)
    : QObject(parent), m_settings(settings), m_player(nullptr)
{
    initializePlayer();
    initializeEnemies();
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
    m_player = new Player(); // No need to pass scene here
    m_player->setPos(400, 300);
    m_items.append(m_player);
}

void Game::movePlayerLeft()
{
    if (m_player->pos().x() > 0)
    {
        m_player->setPos(m_player->x() - 10, m_player->y());
    }
}

void Game::movePlayerRight()
{
    if (m_player->pos().x() + m_player->rect().width() < 800)
    {
        m_player->setPos(m_player->x() + 10, m_player->y());
    }
}

void Game::movePlayerUp()
{
    if (m_player->pos().y() > 0)
    {
        m_player->setPos(m_player->x(), m_player->y() - 10);
    }
}

void Game::movePlayerDown()
{
    if (m_player->pos().y() + m_player->rect().height() < 600)
    {
        m_player->setPos(m_player->x(), m_player->y() + 10);
    }
}

QVector<QGraphicsItem *> Game::items() const
{
    return m_items;
}
