#include "mainmenu.h"

MainMenu::MainMenu():
    _set(TileSet(_path))
{
    _set.addTile("tank1", QRect(0.0f, 0.0f, 20.0f, 20.0f));
    QPixmap pm = _set.getTile("tile1");

    this->addEllipse(QRectF(-100.0, -100.0, 100.0, 100.0));
}
