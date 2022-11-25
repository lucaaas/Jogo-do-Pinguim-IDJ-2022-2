//
// Created by lucas on 13/11/22.
//

#ifndef GAME_ASSETHELPER_H
#define GAME_ASSETHELPER_H


class AssetHelper {
public:

    /**
     * Gets the path to the asset
     * @param assetType type of the asset. Can be audio, img, font or map
     * @param file name of the file
     * @return complete path to the asset
     */
    static std::string GetAssetPath(char *assetType, const char *file);
};


#endif //GAME_ASSETHELPER_H
