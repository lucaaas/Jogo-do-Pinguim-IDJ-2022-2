//
// Created by lucas on 13/11/22.
//

#include <iostream>
#include <fstream>
#include "AssetHelper.h"

std::string AssetHelper::GetAssetPath(const std::string &assetType, const std::string &file) {
    std::string assetsPath = "assets/";
    return assetsPath + assetType + "/" + file;
}

std::ifstream AssetHelper::OpenAsset(const std::string &assetType, const std::string &fileName) {
    std::string path = AssetHelper::GetAssetPath(assetType, fileName);
    std::ifstream file;
    file.open(path, std::ios::out);

    return file;
}