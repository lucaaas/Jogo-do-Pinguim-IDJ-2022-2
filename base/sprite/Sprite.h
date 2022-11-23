//
// Created by lucas on 13/11/22.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include "SDL2/SDL.h"

class Sprite {
private:
    SDL_Texture *texture;
    SDL_Rect clipRect;
    int width;
    int height;

    SDL_Renderer *GetRenderer();

public:
    Sprite();

    explicit Sprite(char *file);

    ~Sprite();

    void DestroyTexture();

    void Open(char *file);

    void SetClip(int x, int y, int w, int h);

    void Render(int x, int y);

    int GetWidth();

    int GetHeight();

    bool IsOpen();
};


#endif //GAME_SPRITE_H
