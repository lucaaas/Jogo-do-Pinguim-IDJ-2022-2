//
// Created by lucas on 13/11/22.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "SDL2/SDL.h"
#include "../../base/sprite/Sprite.h"
#include "../../base/music/Music.h"

class State {
private:
    Sprite bg;
    Music music;
    bool quitRequested;

public:
    State();

    bool QuitRequested() const;

    void LoadAssets();

    void Update(float dt);

    void Render();
};

#endif //GAME_STATE_H
