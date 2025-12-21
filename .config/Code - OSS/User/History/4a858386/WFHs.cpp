#include "../include/picture.hpp"

Picture::Picture(SDL_Renderer* renderer, const std::string& path) {
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &picture_w, &picture_h);
}

Picture::~Picture() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Picture::RenderPicture(SDL_Renderer* renderer, int width, int height) {
    SDL_FRect dst;
    dst.w = picture_w;
    dst.h = picture_h;
    dst.x = (window_w - picture_w) / 2.0f;
    dst.y = (window_h - picture_h) / 2.0f;

    SDL_RenderTexture(renderer, texture, nullptr, &dst);
}
