#include "tank.h"
#include "tankdriver.h"

TankDriver::TankDriver(Game *game) : game_(game) {}

Tank *TankDriver::getTank() { return tank_; }

void TankDriver::initTank(QString tile, float x, float y)
{
    tank_ = new Tank(game_, x, y, tile);
    tank_->SetTile();
}
