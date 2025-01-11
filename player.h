#ifndef PLAYER_H
#define PLAYER_H

#include "tank.h"
#include <QObject>

class Player : public QObject
{
    Q_OBJECT
public:
    Player(Tank * tank);

private:
    Tank * tank_;

signals:

};

#endif // PLAYER_H
