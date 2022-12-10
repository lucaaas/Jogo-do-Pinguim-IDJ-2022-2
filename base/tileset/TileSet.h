//
// Created by lucas on 08/12/22.
//

#ifndef GAME_TILESET_H
#define GAME_TILESET_H


#include "../sprite/Sprite.h"

using namespace std;

/**
 * Class to store the tiles used on TileMap rendering
 */
class TileSet {
private:
    Sprite tileSet;
    int rows;
    int columns;
    int tileWidth;
    int tileHeight;

public:
    TileSet(int tileWidth, int tileHeight, string file);

    void RenderTile(unsigned index, float x, float y);

    int GetTileWidth();

    int GetTileHeigth();
};


#endif //GAME_TILESET_H
