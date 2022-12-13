//
// Created by lucas on 13/11/22.
//

#include "Music.h"
#include "../../types/exceptions/exception/Exception.h"
#include "../resources/Resources.h"

Music::Music() {
    music = nullptr;
}

Music::Music(const std::string file) {
    music = nullptr;
    Open(file);
}

Music::~Music() {
    Stop();
}

void Music::Play(int times) {
    Mix_PlayMusic(music, times);
}

void Music::Stop(int msToStop) {
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(const std::string file) {
    try {
        music = Resources::GetMusic(file);
    } catch (Exception &e) {
        e.Show();
    }
}

bool Music::IsOpen() {
    return music != nullptr;
}