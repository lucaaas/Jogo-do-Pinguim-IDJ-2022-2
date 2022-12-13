//
// Created by lucas on 11/12/22.
//

#ifndef GAME_RESOURCES_H
#define GAME_RESOURCES_H

#include <string>
#include <unordered_map>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

#include "../../types/exceptions/exception/Exception.h"
#include "../../controllers/game/Game.h"

using namespace std;

class Resources {
private:
    static unordered_map<string, SDL_Texture *> imageTable;
    static unordered_map<string, Mix_Music *> musicTable;
    static unordered_map<string, Mix_Chunk *> soundTable;

    static SDL_Texture *LoadImage(const string &file);

    static Mix_Music *LoadMusic(const string &file);

    static Mix_Chunk *LoadSound(const string &file);

public:
    static SDL_Texture *GetImage(const string &file);

    static void ClearImage();

    static Mix_Music *GetMusic(string file);

    static void ClearMusics();

    static Mix_Chunk *GetSound(string file);

    static void ClearSounds();
};


#endif //GAME_RESOURCES_H
