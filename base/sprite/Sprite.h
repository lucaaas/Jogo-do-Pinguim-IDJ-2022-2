//
// Created by lucas on 13/11/22.
//

#ifndef GAME_SPRITE_H
#define GAME_SPRITE_H

#include <string>
#include "SDL2/SDL.h"

class Sprite {
private:
    SDL_Texture *texture;
    SDL_Rect clipRect;
    int width;
    int height;

    SDL_Renderer *GetRenderer();

    void DestroyTexture();

public:
    /**
     * Simple initializes members as nullptr
     */
    Sprite();

    /***
     * Open an image file
     *
     * @param file: char*: image to be opened
     */
    explicit Sprite(std::string file);


    /**
     * Frees memory
     */
    ~Sprite();

    /**
     * Opens an image file
     * @param file image to be open
     * @throws Exception if file does not exists
     */
    void Open(std::string file);

    /**
     * Sets clip with the parameters. If the params w and h differs from the clip dimensions,
     * the image will be resized to fit.
     *
     * @param x horizontal axis where the image must be rendered
     * @param y vertical axis where the image must be rendered
     * @param w width
     * @param h height
     */
    void SetClip(int x, int y, int w, int h);

    /**
     * Renders the image on the coordinates x and y
     * @param x
     * @param y
     */
    void Render(int x, int y);

    /**
     *
     * @return image width
     */
    int GetWidth();

    /**
     *
     * @return image height
     */
    int GetHeight();

    /**
     * Checks if the file is open
     * @return true if it is open
     */
    bool IsOpen();
};


#endif //GAME_SPRITE_H
