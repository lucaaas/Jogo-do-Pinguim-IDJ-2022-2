//
// Created by lucas on 13/12/22.
//

#ifndef GAME_INPUTMANAGER_H
#define GAME_INPUTMANAGER_H

#include <unordered_map>
#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>

using namespace std;

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define ESCAPE_KEY SDLK_ESCAPE
#define SPACE_KEY SDLK_SPACE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT

class InputManager {
private:
    bool mouseState[6];
    int mouseUpdate[6];
    unordered_map<int, bool> keyState;
    unordered_map<int, int> keyUpdate;
    int updateCounter;
    bool quitRequested;
    int mouseX;
    int mouseY;

    InputManager();

    void HandleEvent(SDL_Event &event);

    void HandleKeyboardEvent(SDL_Event &event);

    void HandleMouseEvent(const SDL_Event &event);

public:
    ~InputManager();

    InputManager(InputManager& other) = delete;

    static InputManager &GetInstance();

    void Update();

    bool KeyPress(int key);

    bool KeyRelease(int key);

    bool IsKeyDown(int key);

    bool MousePress(int button);

    bool MouseRelease(int button);

    bool IsMouseDown(int button);

    int GetMouseX();

    int GetMouseY();

    bool QuitRequested();
};


#endif //GAME_INPUTMANAGER_H
