//
// Created by lucas on 13/11/22.
//

#ifndef GAME_ASSETHELPER_H
#define GAME_ASSETHELPER_H

using namespace std;

class AssetHelper {
public:

    /**
     * Gets the path to the asset
     * @param assetType type of the asset. Can be audio, img, font or map
     * @param file name of the file
     * @return complete path to the asset
     */
    static string GetAssetPath(const string &assetType, const string &file);

    static ifstream OpenAsset(const string &assetType, const string &fileName);
};


#endif //GAME_ASSETHELPER_H
