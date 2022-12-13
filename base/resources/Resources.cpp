//
// Created by lucas on 11/12/22.
//

#include "Resources.h"

SDL_Texture *Resources::GetImage(const string &file) {
    unordered_map<string, SDL_Texture *>::const_iterator sprite = imageTable.find(file);
    if (sprite != imageTable.end()) {
        return sprite->second;
    } else {
        SDL_Texture *newSprite = LoadImage(file);
        pair<string, SDL_Texture *> newSpritePair(file, newSprite);
        imageTable.insert(newSpritePair);
    }
}


void Resources::ClearImage() {
    unordered_map<string, SDL_Texture *>::iterator it;
    for (it = imageTable.begin(); it != imageTable.end(); it++) {
        SDL_Texture *sprite = it->second;
        delete &sprite;
    }
}

Mix_Music *Resources::GetMusic(string file) {
    unordered_map<string, Mix_Music *>::const_iterator music = musicTable.find(file);
    if (music != musicTable.end()) {
        return music->second;
    } else {
        Mix_Music *newMusic = LoadMusic(file);
        pair<string, Mix_Music *> newMusicPair(file, newMusic);
        musicTable.insert(newMusicPair);
    }
}

void Resources::ClearMusics() {
    unordered_map<string, Mix_Music *>::iterator it;
    for (it = musicTable.begin(); it != musicTable.end(); it++) {
        Mix_Music *music = it->second;
        delete &music;
    }
}

Mix_Chunk *Resources::GetSound(string file) {
    unordered_map<string, Mix_Chunk *>::const_iterator sound = soundTable.find(file);
    if (sound != soundTable.end()) {
        return sound->second;
    } else {
        Mix_Chunk *mixChunk = LoadSound(file);
        pair<string, Mix_Chunk *> newSoundPair(file, mixChunk);
        soundTable.insert(newSoundPair);
    }
}

void Resources::ClearSounds() {
    unordered_map<string, Mix_Chunk *>::iterator it;
    for (it = soundTable.begin(); it != soundTable.end(); it++) {
        Mix_Chunk *music = it->second;
        delete &music;
    }
}


SDL_Texture *Resources::LoadImage(const string &file) {
    SDL_Renderer *renderer = Game::GetInstance().GetRenderer();
    SDL_Texture *texture = IMG_LoadTexture(renderer, file.c_str());

    if (texture != nullptr) {
        return texture;
    } else {
        std::string error = "An error occurred on loading texture: ";
        throw Exception(error + SDL_GetError());
    }
}

Mix_Music *Resources::LoadMusic(const string &file) {
    Mix_Music *music = Mix_LoadMUS(file.c_str());
    if (music != nullptr) {
        return music;
    } else {
        std::string error = "An error occurred on loading music: ";
        throw Exception(error + SDL_GetError());
    }
}

Mix_Chunk *Resources::LoadSound(const string &file) {
    Mix_Chunk *sound = Mix_LoadWAV(file.c_str());
    if (sound != nullptr) {
        return sound;
    } else {
        std::string error = "An error occurred on loading sound: ";
        throw Exception(error + SDL_GetError());
    }
}
