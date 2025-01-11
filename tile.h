#ifndef TILE_H
#define TILE_H

#include "gameobject.h"
#include <QObject>

class Tile : public QObject, public GameObject
{
    Q_OBJECT
public:
    Tile();

signals:

};

#endif // TILE_H
