#include "enemyhq.h"

QString EnemyHQ::skin()
{
    return "enemyHQ-" + QString::number(frame_ % 7);
}
