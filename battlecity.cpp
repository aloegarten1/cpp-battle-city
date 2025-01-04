#include "battlecity.h"
#include "mainmenu.h"
#include "ui_battlecity.h"

BattleCity::BattleCity(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BattleCity)
{
    ui->setupUi(this);

    game = new Game();

    ui->graphicsView->setScene(game);
}

BattleCity::~BattleCity()
{
    delete ui;
}
