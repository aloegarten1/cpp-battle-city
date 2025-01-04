#include "battlecity.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BattleCity w;
    w.show();
    return a.exec();
}
