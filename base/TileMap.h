//
// Created by lucas on 08/12/22.
//

#ifndef GAME_TILEMAP_H
#define GAME_TILEMAP_H


#include <vector>
#include "tileset/TileSet.h"

using namespace std;

/**
 * Represents the map and its layers simulating a three dimension matrix
 */
class TileMap : public Component {
private:
    vector<int> tileMatrix;
    TileSet *tileSet;
    int mapWidth;
    int mapHeight;
    int mapDepth;

    void SetDimensions(string &line);

    void FillTileMatrix(ifstream &file);

public:
    TileMap(GameObject &associated, string file, TileSet *tileSet);

    void Load(const string &fileName);

    void SetTileSet(TileSet *tileSet);

    int &At(int x, int y, int z = 0);

    void Render();

    void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);

    int getWidth() const;

    int getHeight() const;

    int getDepth() const;

    void Update(float dt) override;

    bool Is(std::string type) override;
};


#endif //GAME_TILEMAP_H
