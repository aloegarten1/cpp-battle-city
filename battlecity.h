#ifndef BATTLECITY_H
#define BATTLECITY_H

#include "game.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BattleCity; }
QT_END_NAMESPACE

/**
 * @brief The BattleCity class
 *
 * @todo Should contain multiple scenes: Menu and Game.
 */

class BattleCity : public QMainWindow
{
    Q_OBJECT

public:
    BattleCity(QWidget *parent = nullptr);
    ~BattleCity();

private:
    Ui::BattleCity *ui;
    Game * game;
};
#endif // BATTLECITY_H
