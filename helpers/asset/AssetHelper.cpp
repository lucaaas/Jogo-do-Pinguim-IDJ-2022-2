//
// Created by lucas on 13/11/22.
//

#include <iostream>
#include "AssetHelper.h"

std::string AssetHelper::GetAssetPath(char *assetType, const char *file) {
    std::string assetsPath = "assets/";
    return assetsPath + assetType + "/" + file;
}
