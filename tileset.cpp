#include "tileset.h"

TileSet::TileSet(const QString &filepath) : _image(new QPixmap(filepath))
{
    init();
}

TileSet::~TileSet()
{
    delete _image;
}

void TileSet::addTile(const QString &name, QRect crop)
{
    _tiles.insert({name, _image->copy(crop)});
}

QPixmap &TileSet::getTile(const QString &name)
{
    return _tiles[name];
}

void TileSet::init()
{
    addTile("player-right-1", QRect(0.0f, 72.0f, 16.0f, 16.0f));
    addTile("player-right-0", QRect(0.0f, 90.0f, 16.0f, 16.0f));

    addTile("player-down-1", QRect(17.0f, 72.0f, 16.0f, 16.0f));
    addTile("player-down-0", QRect(17.0f, 90.0f, 16.0f, 16.0f));

    addTile("player-up-1", QRect(34.0f, 72.0f, 16.0f, 16.0f));
    addTile("player-up-0", QRect(34.0f, 90.0f, 16.0f, 16.0f));

    addTile("player-left-1", QRect(51.0f, 72.0f, 16.0f, 16.0f));
    addTile("player-left-0", QRect(51.0f, 90.0f, 16.0f, 16.0f));

    addTile("enemy-right-1", QRect(0.0f, 0.0f, 16.0f, 16.0f));
    addTile("enemy-right-0", QRect(0.0f, 17.0f, 16.0f, 16.0f));

    addTile("enemy-down-1", QRect(17.0f, 0.0f, 16.0f, 16.0f));
    addTile("enemy-down-0", QRect(17.0f, 17.0f, 16.0f, 16.0f));

    addTile("enemy-up-1", QRect(34.0f, 0.0f, 16.0f, 16.0f));
    addTile("enemy-up-0", QRect(34.0f, 17.0f, 16.0f, 16.0f));

    addTile("enemy-left-1", QRect(51.0f, 0.0f, 16.0f, 16.0f));
    addTile("enemy-left-0", QRect(51.0f, 17.0f, 16.0f, 16.0f));

    addTile("wall1", QRect(235.0f, 0.0f, 16.0f, 16.0f));

    addTile("concreteWall1", QRect(267.0f, 48.0f, 16.0f, 16.0f));

    addTile("projectile0", QRect(235.0f, 95.0f, 16.0f, 16.0f));
    addTile("projectile1", QRect(251.0f, 95.0f, 16.0f, 16.0f));
    addTile("projectile2", QRect(267.0f, 95.0f, 16.0f, 16.0f));
    addTile("projectile3", QRect(283.0f, 95.0f, 16.0f, 16.0f));
    addTile("projectile4", QRect(267.0f, 95.0f, 16.0f, 16.0f));
    addTile("projectile5", QRect(251.0f, 95.0f, 16.0f, 16.0f));

    addTile("enemyHQ-0", QRect(235.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-1", QRect(251.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-2", QRect(267.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-3", QRect(283.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-4", QRect(299.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-5", QRect(315.0f, 127.0f, 16.0f, 16.0f));
    addTile("enemyHQ-6", QRect(331.0f, 127.0f, 16.0f, 16.0f));

    addTile("win", QRect(129.0f, 146.0f, 128.0f, 72.0f));
    addTile("loose", QRect(0.0f, 146.0f, 128.0f, 72.0f));
}


float TileSet::scale()
{
    // hardcoded
    return 48.;
}
