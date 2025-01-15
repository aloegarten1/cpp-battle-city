#include "concretewall.h"

void ConcreteWall::update()
{
    if (frame_ == 0)
    {
        setTile();
    }
    return;
}

QString ConcreteWall::skin()
{
    return "concreteWall1";
}
