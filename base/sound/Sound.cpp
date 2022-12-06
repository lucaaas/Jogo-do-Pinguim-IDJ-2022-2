//
// Created by lucas on 29/11/22.
//

#include "Sound.h"
#include "../../types/exceptions/exception/Exception.h"
#include "../../types/exceptions/methodNotImplemented/MethodNotImplementedException.h"

Sound::Sound(GameObject &associated) : Component(associated) {
    chunk = nullptr;
}

Sound::Sound(GameObject &associated, const std::string &file) : Sound(associated) {
    Open(file);
}

Sound::~Sound() {
    if (chunk != nullptr) {
        Stop();
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times) {
    channel = Mix_PlayChannel(-1, chunk, times - 1);
}

void Sound::Stop() {
    if (chunk != nullptr) {
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(const std::string& file) {
    chunk = Mix_LoadWAV(file.c_str());
    if (chunk == nullptr) {
        std::string error = "An error occurred on loading music: ";
        throw Exception(error + SDL_GetError());
    }
}

bool Sound::IsOpen() {
    return chunk != nullptr;
}

bool Sound::Is(std::string type) {
    return type == "Sound";
}

void Sound::Update(float dt) {
    // do nothing
}

void Sound::Render() {
    // do nothing
}

