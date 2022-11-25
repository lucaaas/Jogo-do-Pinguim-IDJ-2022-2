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
    /**
     * Initializes this
     */
    State();

    /**
     * @return true if quit was requested
     */
    bool QuitRequested() const;

    /**
     * Preloads the assets that will be used
     */
    void LoadAssets();

    /**
     * Updates the different entities state
     * @param dt
     */
    void Update(float dt);

    /**
     * Renders the entities (scenarios, HDU etc)
     */
    void Render();
};

#endif //GAME_STATE_H
