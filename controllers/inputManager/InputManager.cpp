//
// Created by lucas on 13/12/22.
//

#include "InputManager.h"

InputManager::InputManager() : mouseState{},
                               mouseUpdate{},
                               quitRequested(false),
                               updateCounter(0),
                               mouseX(0),
                               mouseY(0) {}

InputManager::~InputManager() {}


InputManager &InputManager::GetInstance() {
    static InputManager instance;
    return instance;
}

void InputManager::Update() {
    SDL_GetMouseState(&mouseX, &mouseY);
    quitRequested = false;

    SDL_Event event;
    updateCounter++;

    while (SDL_PollEvent(&event)) {
        HandleEvent(event);
    }
}

bool InputManager::KeyPress(int key) {
    return keyState[key] && keyUpdate[key] == updateCounter;
}

bool InputManager::KeyRelease(int key) {
    return !keyState[key] && keyUpdate[key] == updateCounter;
}

bool InputManager::IsKeyDown(int key) {
    return keyState[key];
}

bool InputManager::MousePress(int button) {
    return mouseState[button] && mouseUpdate[button] == updateCounter;
}

bool InputManager::MouseRelease(int button) {
    return !mouseState[button] && mouseUpdate[button] == updateCounter;
}

bool InputManager::IsMouseDown(int button) {
    return mouseState[button];
}

int InputManager::GetMouseX() {
    return mouseX;
}

int InputManager::GetMouseY() {
    return mouseY;
}

bool InputManager::QuitRequested() {
    return quitRequested;
}

void InputManager::HandleEvent(SDL_Event &event) {
    if (event.type == SDL_QUIT) {
        quitRequested = true;
    } else if (!event.key.repeat) {
        if (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_MOUSEBUTTONUP) {
            HandleMouseEvent(event);
        } else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP) {
            HandleKeyboardEvent(event);
        }
    }
}

void InputManager::HandleMouseEvent(const SDL_Event &event) {
    int button = event.button.button;
    mouseState[button] = event.button.state;
    mouseUpdate[button] = updateCounter;
}

void InputManager::HandleKeyboardEvent(SDL_Event &event) {
    int key = event.key.keysym.sym;

    if (key == SDLK_ESCAPE) {
        quitRequested = true;
    } else {
        keyState[key] = event.key.state;
        keyUpdate[key] = updateCounter;
    }
}

