//
// Created by lucas on 13/11/22.
//

#include <cstring>
#include "AssetService.h"

char *AssetService::GetAssetPath(char *assetType, const char *file) {
    char *path = (char *) "/assets/";

    strcat(assetType, "/");
    strcat(path, assetType);
    strcat(path, file);

    return path;
}
