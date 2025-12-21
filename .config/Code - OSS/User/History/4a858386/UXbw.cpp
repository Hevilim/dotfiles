#include "../include/picture.hpp"

Picture::Picture(SDL_Renderer* renderer, const std::string& path) {
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return;
    }
    SDL_QueryTexture(texture, nullptr, nullptr, &texW, &texH);
}