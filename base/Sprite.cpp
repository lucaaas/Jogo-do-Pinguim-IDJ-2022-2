//
// Created by lucas on 13/11/22.
//


#include <stdexcept>
#include <iostream>
#include "SDL2/SDL_image.h"
#include "../controllers/Game.h"

#include "Sprite.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(char *file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    DestroyTexture();
}

void Sprite::DestroyTexture() {
    SDL_DestroyTexture(texture);
}

SDL_Renderer *Sprite::GetRenderer() {
    return Game::GetInstance().GetRenderer();
}

void Sprite::Open(char *file) {
    if (texture != nullptr) {
        DestroyTexture();
    }

    texture = IMG_LoadTexture(GetRenderer(), file);
    if (texture == nullptr) {
        throw std::runtime_error(strcat("An error occurred on loading texture: ", SDL_GetError()));
    }

    int result_query = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    if (result_query != 0) {
        throw std::runtime_error(strcat("An error occurred on querying texture: ", SDL_GetError()));
    }

    SetClip(0, 0, width, height);
}

void Sprite::SetClip(int x, int y, int w, int h) {
    clipRect = SDL_Rect();
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
}


void Sprite::Render(int x, int y) {
    SDL_Rect destinyRect = SDL_Rect();
    destinyRect.x = x;
    destinyRect.y = y;
    destinyRect.w = clipRect.w;
    destinyRect.h = clipRect.h;

    SDL_RenderCopy(GetRenderer(), texture, &clipRect, &destinyRect);
}

int Sprite::GetWidth() {
    return width;
}

int Sprite::GetHeight() {
    return height;
}

bool Sprite::IsOpen() {
    return texture != nullptr;
}



