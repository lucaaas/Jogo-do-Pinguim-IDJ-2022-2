//
// Created by lucas on 08/12/22.
//

#include <fstream>
#include "TileMap.h"
#include "../helpers/asset/AssetHelper.h"
#include "../helpers/string/StringHelper.h"

TileMap::TileMap(GameObject &associated, string file, TileSet *tileSet) : Component(associated), tileSet(tileSet) {
    Load(file);
}

void TileMap::Load(const string &fileName) {
    ifstream file = AssetHelper::OpenAsset("map", fileName);
    string line;

    getline(file, line);
    SetDimensions(line);

    FillTileMatrix(file);
    file.close();
}

void TileMap::SetTileSet(TileSet *tileSet) {
    this->tileSet = tileSet;
}

int &TileMap::At(int x, int y, int z) {
    int index = (mapWidth * mapHeight * z) + (mapWidth * x) + y;
    return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
    for (int i = 0; i < mapWidth; i++) {
        for (int j = 0; j < mapHeight; j++) {
            tileSet->RenderTile(At(i, j, layer), cameraX, cameraY);
        }
    }
}

void TileMap::Render() {
    for (int i = 0; i < mapDepth; i++) {
        RenderLayer(i, associated.box.getX(), associated.box.getY());
    }
}


void TileMap::FillTileMatrix(ifstream &file) {
    string line;
    while (getline(file, line)) {
        line = StringHelper::Trim(line);
        if (!line.empty()) {
            vector<string> tiles = StringHelper::Split(line, ",");
            for (const auto &tile: tiles) {
                tileMatrix.push_back(stoi(tile) - 1);
            }
        }
    }
}

void TileMap::SetDimensions(string &line) {
    vector<string> dimensions = StringHelper::Split(line, ",");
    mapWidth = stoi(dimensions[0]);
    mapHeight = stoi(dimensions[1]);
    mapDepth = stoi(dimensions[2]);
}

int TileMap::getWidth() const {
    return mapWidth;
}

int TileMap::getHeight() const {
    return mapHeight;
}

int TileMap::getDepth() const {
    return mapDepth;
}

void TileMap::Update(float dt) {
    // do nothing
}

bool TileMap::Is(std::string type) {
    return type == "TileMap";
}
