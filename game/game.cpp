#include <random>

#include "game.h"
#include "concretewall.h"
#include "enemyhq.h"
#include "gameobject.h"
#include "enemy.h"
#include "projectile.h"
#include "tank.h"
#include "wall.h"
#include "player.h"

Game::Game(Settings *settings)
    : state_(GameState::RUNNING), settings_(settings), player_(nullptr), items_(), enemies_()
{
}

Game::~Game()
{
    for (GameObject *item : items_)
    {
        delete item;
    }

    for (Enemy *item : enemies_)
    {
        delete item;
    }

    delete player_;
}

void Game::init()
{
    initializePlayer();
    initializeEnemies();
    initializeMap();
}

void Game::setState(GameState state)
{

    switch (state)
    {
    case GameState::RUNNING:
    {
        if (state_ == GameState::PAUSED)
        {
            state_ = state;
        }
        break;
    }
    case GameState::WIN:
    case GameState::LOOSE:
    case GameState::PAUSED:
    {
        if (state_ == GameState::RUNNING)
        {
            state_ = state;
        }
        break;
    }
    default:
        break;
    }
}

void Game::update()
{
    for (Enemy *enemy : enemies_)
    {
        enemy->AI();
    }

    for (GameObject *item : items_)
    {
        item->update();
    }
}

void Game::destroyGameObject(GameObject *obj)
{
    auto it = std::find(items_.begin(), items_.end(), obj);
    items_.erase(it);
    delete obj;
}

void Game::addGameObject(GameObject *obj)
{
    items_.append(obj);
}

void Game::initializeEnemies()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis13(0, 13);
    std::uniform_int_distribution<> dis9(0, 9);

    int enemiesCount = settings_->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i)
    {

        int x = 2 + dis13(gen);
        int y = 2 + dis9(gen);

        Enemy *enemy = new Enemy(this);
        enemy->initTank("enemy", x, y);
        addGameObject(enemy->getTank());
        enemies_.append(enemy);
    }
}

void Game::initializePlayer()
{
    player_ = new Player(this);
    player_->initTank("player", 1, 10);
    addGameObject(player_->getTank());
}

void Game::initializeMap()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis100(0, 100);

    EnemyHQ *hq = new EnemyHQ(this, 8, 2);
    addGameObject(hq);

    for (int ix = 0; ix < 16; ix++)
    {

        ConcreteWall *cwall = new ConcreteWall(this, ix, 0);
        addGameObject(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, ix, 11);
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

            int g = dis100(gen);

            if (g > 25)
            {
                continue;
            }

            Wall *wall = new Wall(this, ix, jy);
            addGameObject(wall);
        }
    }

    for (int j = 1; j < 11; j++)
    {
        ConcreteWall *cwall = new ConcreteWall(this, 0, j);
        addGameObject(cwall);
        ConcreteWall *cwall2 = new ConcreteWall(this, 15, j);
        addGameObject(cwall2);
    }
}

void Game::setPlayerCommand(int c)
{

    player_->setCommand(c);
}

void Game::unsetPlayerCommand(int c)
{
    player_->unsetCommand(c);
}

GameObject *Game::collide(GameObject *obj, float x, float y)
{

    GameObject *dst = nullptr;

    for (GameObject *item : items_)
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

                if (obj == nullptr)
                {
                    break;
                }
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
    if (player_->getTank() == tank)
    {
        player_->kill();
        loose();
        return;
    }

    for (Enemy *enemy : enemies_)
    {
        if (enemy->getTank() == tank)
        {
            enemy->kill();
        }
    }
}

void Game::loose()
{
    setState(GameState::LOOSE);
}

void Game::win()
{

    for (Enemy *enemy : enemies_)
    {
        enemy->kill();
    }
    setState(GameState::WIN);
}
