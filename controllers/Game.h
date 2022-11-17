//
// Created by lucas on 11/11/22.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "SDL2/SDL.h"
#include "State.h"

class Game {
private:
    static Game *instance;

    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;

    Game(const char *title, int width, int height);

    void Init();

    void InitSdl() const;

    void InitImage() const;

    void InitAudio() const;

public:
    ~Game();

    static Game &GetInstance();

    SDL_Renderer *GetRenderer();

    State &GetState();

    void Run();
};


#endif //GAME_GAME_H
