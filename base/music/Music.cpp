//
// Created by lucas on 13/11/22.
//

#include "Music.h"
#include "../../types/exceptions/Exception.h"

Music::Music() {
    music = nullptr;
}

Music::Music(const char *file) {
    music = nullptr;
    Open(file);
}

Music::~Music() {
    DestroyMusic();
}

void Music::DestroyMusic() {
    Mix_FreeMusic(music);
}

void Music::Play(int times) {
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(const char *file) {
    if (music != nullptr) {
        DestroyMusic();
    }

    music = Mix_LoadMUS(file);
    if (music == nullptr) {
        std::string error = "An error occurred on loading music: ";
        throw Exception(error + SDL_GetError());
    }
}

bool Music::IsOpen() {
    return false;
}