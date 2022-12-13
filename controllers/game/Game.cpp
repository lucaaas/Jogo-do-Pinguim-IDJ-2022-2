//
// Created by lucas on 11/11/22.
//

#include <iostream>

#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

#include "Game.h"
#include "../../types/exceptions/exception/Exception.h"
#include "../../base/resources/Resources.h"

Game *Game::instance = nullptr;

Game::Game(const std::string title, int width, int height) {
    InitSdl();
    InitImage();
    InitAudio();

    CreateWindow(title, width, height);
    CreateRenderer();

    instance = this;
    state = new State();
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
        try {
            SDL_RenderClear(renderer);
            state->Update(0.0);
            state->Render();

            SDL_RenderPresent(renderer);
            SDL_Delay(33);
        } catch (std::exception &e) {
            std::cerr << e.what() << "\n";
        }
    }

    Resources::ClearAllResources();
}

void Game::CreateWindow(const std::string title, int width, int height) {
    window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
    if (window == nullptr) {
        std::string error = "An error occurred on creating window: ";
        throw Exception(error + SDL_GetError());
    }
}

void Game::CreateRenderer() {
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::string error = "An error occurred on creating renderer: ";
        throw Exception(error + SDL_GetError());
    }
}

void Game::InitAudio() const {
    int mixesInitialized = Mix_Init(MIX_INIT_MP3);
    if (mixesInitialized == 0) {
        std::string error = "An error occurred on initializing mixes: ";
        throw Exception(error + SDL_GetError());
    }

    int audioInitialized = Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
    if (audioInitialized != 0) {
        std::string error = "An error occurred on initializing audio: ";
        throw Exception(error + SDL_GetError());
    }

    int channelNumbers = 32;
    int allocatedChannels = Mix_AllocateChannels(channelNumbers);
    if (allocatedChannels != channelNumbers) {
        std::string error = "An error occurred on allocating channels: ";
        throw Exception(error + SDL_GetError());
    }
}

void Game::InitImage() const {
    int imgsInitialized = IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF);
    if (imgsInitialized == 0) {
        std::string error = "An error occurred on initializing SDL_IMAGE: ";
        throw Exception(error + SDL_GetError());
    }
}

void Game::InitSdl() const {
    int sdlInitialized = SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER);
    if (sdlInitialized != 0) {
        std::string error = "An error occurred on initializing SDL: ";
        throw Exception(error + SDL_GetError());
    }
}
