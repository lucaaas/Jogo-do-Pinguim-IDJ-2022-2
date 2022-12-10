//
// Created by lucas on 08/12/22.
//

#include "TileSet.h"

GameObject tileSetGO = GameObject();

TileSet::TileSet(int tileWidth, int tileHeight, string file) : tileHeight(tileHeight), tileWidth(tileWidth),
                                                               tileSet(Sprite(tileSetGO, file)) {
    rows = tileSet.GetHeight() / tileHeight;
    columns = tileSet.GetWidth() / tileWidth;
}

void TileSet::RenderTile(unsigned int index, float x, float y) {
    if (index < (rows * columns)) {
        tileSet.Render(x, y);
    }
}

int TileSet::GetTileWidth() {
    return tileWidth;
}

int TileSet::GetTileHeigth() {
    return tileHeight;
}

