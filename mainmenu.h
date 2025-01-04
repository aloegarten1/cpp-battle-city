#ifndef MAINMENU_H
#define MAINMENU_H

#include "tileset.h"

#include <QGraphicsScene>

class MainMenu : public QGraphicsScene
{
public:
    explicit MainMenu();

protected:
    const QString _path = ":/sheets/tanks.png";
    TileSet _set;
};

#endif // MAINMENU_H
