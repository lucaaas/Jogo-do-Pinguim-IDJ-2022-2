//
// Created by lucas on 13/11/22.
//

#include <stdexcept>
#include "State.h"
#include "../helpers/AssetService.h"

State::State() {
    quitRequested = false;
    LoadAssets();
}

void State::LoadAssets() {
    bg = Sprite(AssetService::GetAssetPath((char *) "img", "ocean.jpg"));
    music = Music(AssetService::GetAssetPath((char *) "audio", "stageState.ogg"));
}

bool State::QuitRequested() const {
    return quitRequested;
}

void State::Render() {
    bg.Render(0, 0);
}

void State::Update(float dt) {
    quitRequested = SDL_QuitRequested();
}
