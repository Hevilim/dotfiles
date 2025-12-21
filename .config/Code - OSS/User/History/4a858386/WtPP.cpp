#include "../include/picture.hpp"
#include <SDL3/SDL.h>

Picture::Picture(SDL_Renderer* renderer, const std::string& path) {
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return;
    }

    SDL_GetTextureDimensions(texture, &picture_w, &picture_h);  // ✅ вместо SDL_QueryTexture
}

Picture::~Picture() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Picture::RenderPicture(SDL_Renderer* renderer, int window_w, int window_h) {
    SDL_FRect dst;
    dst.w = picture_w;
    dst.h = picture_h;
    dst.x = (window_w - picture_w) / 2.0f;
    dst.y = (window_h - picture_h) / 2.0f;

    SDL_RenderTexture(renderer, texture, nullptr, &dst);
}
