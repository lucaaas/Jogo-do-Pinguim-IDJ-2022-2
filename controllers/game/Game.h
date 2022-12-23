//
// Created by lucas on 11/11/22.
//

#ifndef GAME_GAME_H
#define GAME_GAME_H

#include "SDL2/SDL.h"
#include "../state/State.h"

class State;

class Game {
private:
    static Game *instance;

    SDL_Window *window;
    SDL_Renderer *renderer;
    State *state;

    Game(std::string title, int width, int height);

    void CreateWindow(std::string title, int width, int height);

    void CreateRenderer();

    void InitSdl() const;

    void InitImage() const;

    void InitAudio() const;

public:
    /**
     * Deletes the State, stops musics, removes the images and closes the window
     */
    ~Game();

    /**
     * Gets or creates the instance of Game
     * @return a instance of Game
     */
    static Game &GetInstance();

    /**
     *
     * @return the Renderer
     */
    SDL_Renderer *GetRenderer();


    /**
     *
     * @return the current State
     */
    State &GetState();

    /**
     * Inits the game and control what render, handle input and maintain the current state
     */
    void Run();
};


#endif //GAME_GAME_H
