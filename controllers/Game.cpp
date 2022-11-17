//
// Created by lucas on 11/11/22.
//

#include <stdexcept>
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "Game.h"


Game::Game(const char *title, int width, int height) {
    Init();

    state = new State;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        throw std::runtime_error(strcat("An error occurred on creating window: ", SDL_GetError()));
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        throw std::runtime_error(strcat("An error occurred on creating renderer: ", SDL_GetError()));
    }
}

Game::~Game() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    Mix_CloseAudio();
    Mix_Quit();

    IMG_Quit();
    SDL_Quit();
}

Game &Game::GetInstance() {
    if (instance == nullptr) {
        instance = new Game("Lucas Silva (15/0016018)", 1024, 600);
    }

    return *instance;
}

SDL_Renderer *Game::GetRenderer() {
    return renderer;
}

State &Game::GetState() {
    return *state;
}

void Game::Run() {
    while (!state->QuitRequested()) {
        state->Update(0.0);
        state->Render();

        SDL_RenderPresent(renderer);
        SDL_Delay(33);
    }
}

void Game::Init() {
    InitSdl();
    InitImage();
    InitAudio();
}

void Game::InitAudio() const {
    int mixesInitialized = Mix_Init(MIX_INIT_MP3);
    if (mixesInitialized == 0) {
        throw std::runtime_error(strcat("An error occurred on initializing mixes: ", SDL_GetError()));
    }

    int audioInitialized = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    if (audioInitialized != 0) {
        throw std::runtime_error(strcat("An error occurred on initializing audio: ", SDL_GetError()));
    }

    int channelNumbers = 32;
    int allocatedChannels = Mix_AllocateChannels(channelNumbers);
    if (allocatedChannels != channelNumbers) {
        throw std::runtime_error(strcat("An error occurred on allocating channels: ", SDL_GetError()));
    }
}

void Game::InitImage() const {
    int imgsInitialized = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    if (imgsInitialized == 0) {
        throw std::runtime_error(strcat("An error occurred on initializing SDL_Image: ", SDL_GetError()));
    }
}

void Game::InitSdl() const {
    int sdlInitialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if (sdlInitialized != 0) {
        throw std::runtime_error(strcat("An error occurred on initializing SDL: ", SDL_GetError()));
    }
}
