#include "tank.h"
#include "tankdriver.h"

TankDriver::TankDriver(Game *game) : game_(game), alive_(true) {}

Tank *TankDriver::getTank() { return tank_; }

void TankDriver::initTank(QString tile, float x, float y)
{
    tank_ = new Tank(game_, x, y, tile);
    tank_->SetTile();
}


void TankDriver::kill(){
    alive_ = false;
}
