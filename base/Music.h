//
// Created by lucas on 13/11/22.
//

#ifndef GAME_MUSIC_H
#define GAME_MUSIC_H

#include <string>
#include "SDL2/SDL_mixer.h"

class Music {
private:
    Mix_Music *music;

public:
    Music();

    explicit Music(const char *file);

    ~Music();

    void Play(int times = -1);

    void Stop(int msToStop = 1500);

    void Open(const char *file);

    bool IsOpen();

    void DestroyMusic();
};


#endif //GAME_MUSIC_H
