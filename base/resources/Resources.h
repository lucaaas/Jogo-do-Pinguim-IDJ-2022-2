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
    unordered_map<string, SDL_Texture *> imageTable;
    unordered_map<string, Mix_Music *> musicTable;
    unordered_map<string, Mix_Chunk *> soundTable;

    SDL_Texture *LoadImage(const string &file);

public:
    SDL_Texture *GetImage(const string &file);

    void ClearImage();

    Mix_Music *GetMusic(string file);

    void ClearMusics();

    Mix_Chunk *GetSound(string file);

    void ClearSounds();

    Mix_Music *LoadMusic(const string &file);

    Mix_Chunk * LoadSound(const string &file);
};


#endif //GAME_RESOURCES_H
