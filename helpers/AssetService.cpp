//
// Created by lucas on 13/11/22.
//

#include <cstring>
#include <iostream>
#include "AssetService.h"

char *AssetService::GetAssetPath(char *assetType, const char *file) {
    char *assetsPath = (char *) "/assets/";
    char fullPath[255] = "";

    strcat(fullPath, assetsPath);
    strcat(fullPath, assetType);
    strcat(fullPath, "/");
    strcat(fullPath, file);

    return fullPath;
}
