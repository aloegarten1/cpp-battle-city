#ifndef TILESET_H
#define TILESET_H

#include <map>
#include <QPixmap>

class TileSet
{
public:
    static TileSet *getInstance()
    {
        static TileSet *instance = new TileSet(":/images/images/tanks3.png");
        return instance;
    }
    ~TileSet();

    void addTile(const QString &name, QRect crop);
    QPixmap &getTile(const QString &name);

private:
    TileSet(const QString &filepath);

    void init();
    QPixmap *_image;
    std::map<QString, QPixmap> _tiles;
};

#endif // TILESET_H
