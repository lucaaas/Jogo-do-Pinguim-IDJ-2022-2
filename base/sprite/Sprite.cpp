//
// Created by lucas on 13/11/22.
//

#include "SDL2/SDL_image.h"

#include "../../controllers/game/Game.h"
#include "Sprite.h"
#include "../../types/exceptions/Exception.h"

Sprite::Sprite() {
    texture = nullptr;
}

Sprite::Sprite(std::string file) {
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite() {
    DestroyTexture();
}

SDL_Renderer *Sprite::GetRenderer() {
    return Game::GetInstance().GetRenderer();
}

void Sprite::Open(std::string file) {
    if (texture != nullptr) {
        DestroyTexture();
    }

    texture = IMG_LoadTexture(GetRenderer(), file.c_str());
    if (texture == nullptr) {
        std::string error = "An error occurred on loading texture: ";
        throw Exception(error + SDL_GetError());
    }

    int result_query = SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    if (result_query != 0) {
        std::string error = "An error occurred on querying texture: ";
        throw Exception(error + SDL_GetError());
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

void Sprite::DestroyTexture() {
    SDL_DestroyTexture(texture);
}

