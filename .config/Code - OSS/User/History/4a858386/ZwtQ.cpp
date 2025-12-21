#include "../include/picture.hpp"
#include <SDL3/SDL.h>
#include <SDL3/SDL_render.h> // добавь на всякий случай

Picture::Picture(SDL_Renderer* renderer, const std::string& path) {
    texture = IMG_LoadTexture(renderer, path.c_str());
    if (!texture) {
        SDL_Log("Failed to load image: %s", SDL_GetError());
        return;
    }

    SDL_GetTextureSize(texture, &picture_w, &picture_h); // ✅ Надёжный способ
}
