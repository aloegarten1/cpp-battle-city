#ifndef TILESET_H
#define TILESET_H

#include <map>
#include <QPixmap>

class TileSet
{
public:
    /*
     * @param filepath: path to image
     */
    TileSet(const QString& filepath);
    ~TileSet();

    void addTile(const QString& name, QRect crop);
    QPixmap& getTile(const QString& name);

private:
    QPixmap * _image;
    std::map<QString, QPixmap> _tiles;
};

#endif // TILESET_H
