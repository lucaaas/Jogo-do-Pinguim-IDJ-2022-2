//
// Created by lucas on 13/11/22.
//

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <memory>
#include "SDL2/SDL.h"
#include "../../base/music/Music.h"
#include "../../base/sprite/Sprite.h"

class State {
private:
    Sprite bg;
    Music music;
    bool quitRequested;
    std::vector<std::unique_ptr<GameObject>> objectArray;

    void AddMap();

public:
    /**
     * Initializes this
     */
    State();

    ~State();

    void AddObject(int mouseX, int mouseY);

    /**
     * @return true if quit was requested
     */
    bool QuitRequested() const;

    /**
     * Preloads the assets that will be used
     */
    void LoadAssets();

    void Input();

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
