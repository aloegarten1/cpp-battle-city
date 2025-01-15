#include "game.h"
#include "concretewall.h"
#include "enemyhq.h"
#include "gameobject.h"
#include "enemy.h"
#include "projectile.h"
#include "tank.h"
#include "tileset.h"
#include "wall.h"
#include "player.h"
#include <QRandomGenerator>

Game::Game(Settings *settings, QObject *parent)
    : QObject(parent), m_settings(settings), m_player(nullptr)
{
}

Game::~Game()
{
    for (GameObject *item : m_items)
    {
        emit gameObjectDestroyed(item);
        delete item;
    }

    for (Enemy *item : m_enemies)
    {
        delete item;
    }

    delete m_player;
}

void Game::init()
{
    initializePlayer();
    initializeEnemies();
    initializeMap();

    connect(&m_timer, &QTimer::timeout, this, &Game::onGameUpdateTimer);
    m_timer.start(50); // Update every x milliseconds

}

float Game::scale()
{
    // hardcoded
    return 48.;
}

void Game::destroyGameObject(GameObject *obj)
{

    emit gameObjectDestroyed(obj);

    auto it = std::find(m_items.begin(), m_items.end(), obj);
    m_items.erase(it);
    delete obj;
}

void Game::addGameObject(GameObject *obj)
{
    m_items.append(obj);
    emit gameObjectAdded(obj);
}

void Game::initializeEnemies()
{
    int enemiesCount = m_settings->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i)
    {

        int x = 2 + QRandomGenerator::global()->bounded(14);
        int y = 2 + QRandomGenerator::global()->bounded(10);

        Enemy *enemy = new Enemy(this);
        enemy->initTank("enemy", x, y);
        addGameObject(enemy->getTank());
        m_enemies.append(enemy);
    }
}

void Game::initializePlayer()
{
    m_player = new Player(this);
    m_player->initTank("player", 1, 10);
    addGameObject(m_player->getTank());
}

void Game::initializeMap()
{

    EnemyHQ *hq = new EnemyHQ(this, 8, 2);
    hq->SetTile();
    addGameObject(hq);

    for (int ix = 0; ix < 16; ix++)
    {

        ConcreteWall *cwall = new ConcreteWall(this, ix, 0);
        cwall->SetTile();
        addGameObject(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, ix, 11);
        cwall2->SetTile();
        addGameObject(cwall2);

        for (int jy = 1; jy < 11; jy++)
        {

            if (ix == 1 && jy == 10) // hardcoded player position
            {
                continue;
            }

            if (collide(nullptr, ix, jy)) // enemies, etc
            {
                continue;
            }

            int g = QRandomGenerator::global()->bounded(100);

            if (g > 25)
            {
                continue;
            }

            Wall *wall = new Wall(this, ix, jy);
            wall->SetTile();
            addGameObject(wall);
        }
    }

    for (int j = 1; j < 11; j++)
    {
        ConcreteWall *cwall = new ConcreteWall(this, 0, j);
        cwall->SetTile();
        addGameObject(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, 15, j);
        cwall2->SetTile();
        addGameObject(cwall2);
    }
}

void Game::onGameUpdateTimer()
{

    for (Enemy *enemy : m_enemies)
    {

        enemy->AI();
    }

    for (GameObject *item : m_items)
    {

        item->update();
    }
}

void Game::setPlayerCommand(int c)
{

    m_player->setCommand(c);
}

void Game::unsetPlayerCommand(int c)
{
    m_player->unsetCommand(c);
}

GameObject *Game::collide(GameObject *obj, float x, float y)
{

    GameObject *dst = nullptr;

    for (GameObject *item : m_items)
    {
        if (obj == item || !item->collideable())
        {
            continue;
        }

        bool collided = std::abs(x - item->x()) < 0.75 && std::abs(y - item->y()) < 0.75;

        if (collided)
        {
            if (dst == nullptr)
            {
                dst = item;
                continue;
            }

            // TODO simplify
            float oldDisstance = (obj->x() - dst->x()) * (obj->x() - dst->x()) + (obj->y() - dst->y()) * (obj->y() - dst->y());     // distance between obj & dst (square)
            float newDisstance = (obj->x() - item->x()) * (obj->x() - item->x()) + (obj->y() - item->y()) * (obj->y() - item->y()); // distance between obj & item (square)

            if (oldDisstance > newDisstance)
            {
                dst = item;
                continue;
            }
        }
    }

    if (dst == nullptr)
    {
        return nullptr;
    }

    if (obj != nullptr && typeid(*obj) == typeid(Projectile))
    {
        destroyGameObject(obj);

        if (dst->destructable())
        {
            if (typeid(*dst) == typeid(Tank))
            {
                onTankKilled(dynamic_cast<Tank *>(dst));
            }

            if (typeid(*dst) == typeid(EnemyHQ))
            {
                win();
            }

            destroyGameObject(dst);
        }
    }

    return dst;
}

void Game::onTankKilled(Tank *tank)
{
    if (m_player->getTank() == tank)
    {
        m_player->kill();
        loose();
        return;
    }

    for (Enemy *enemy : m_enemies)
    {
        if (enemy->getTank() == tank)
        {
            enemy->kill();
        }
    }
}

void Game::loose()
{
    m_timer.stop();
    popup("loose");
}

void Game::win()
{

    m_timer.stop();
    for (Enemy *enemy : m_enemies)
    {
        enemy->kill();
    }
    popup("win");
}

void Game::popup(QString name)
{
    TileSet *tl = TileSet::getInstance();
    QPixmap img = tl->getTile(name);
    QGraphicsPixmapItem *pop = new QGraphicsPixmapItem(img);
    pop->setPos(336, 264);
    emit gameObjectAdded(pop);
}
