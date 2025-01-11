#include "tank.h"



void Tank::moveLeft()
{

    setPos(x() - 10, y());
}

void Tank::moveRight()
{

    setPos(x() + 10, y());
}

void Tank::moveUp()
{

    setPos(x(), y() - 10);
}

void Tank::moveDown()
{

    setPos(x(), y() + 10);
}
