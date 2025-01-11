#include "tileset.h"

TileSet::TileSet(const QString& filepath) :
    _image(new QPixmap(filepath))
{}

TileSet::~TileSet() {
    delete _image;
}

void TileSet::addTile(const QString& name, QRect crop) {
    _tiles.insert({name, _image->copy(crop)});
}

QPixmap& TileSet::getTile(const QString& name) {
    return _tiles[name];
}
