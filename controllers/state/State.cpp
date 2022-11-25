//
// Created by lucas on 13/11/22.
//

#include <stdexcept>
#include "State.h"
#include "../../helpers/asset/AssetHelper.h"

State::State() : bg(AssetHelper::GetAssetPath("img", "ocean.jpg")),
                 music(AssetHelper::GetAssetPath("audio", "stageState.ogg")) {
    quitRequested = false;

    music.Play();
}

void State::LoadAssets() {
    bg = Sprite(AssetHelper::GetAssetPath("img", "ocean.jpg"));

    music = Music(AssetHelper::GetAssetPath("audio", "stageState.ogg"));
    music.Play();
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
