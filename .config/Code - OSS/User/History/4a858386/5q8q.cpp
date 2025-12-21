#include "../include/picture.hpp"

Picture::Picture(SDL_Renderer* renderer, const std::string& path) {
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return 1;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
}

Picture::~Picture() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void Picture::RenderPicture(SDL_Renderer* renderer, int width, int windowHeight) {
    SDL_FRect dst;
    dst.w = texW;
    dst.h = texH;
    dst.x = (windowWidth - texW) / 2.0f;
    dst.y = (windowHeight - texH) / 2.0f;

    SDL_RenderTexture(renderer, texture, nullptr, &dst);
}
