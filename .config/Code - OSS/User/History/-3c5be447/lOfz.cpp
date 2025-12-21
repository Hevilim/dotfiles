#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    SDL_PixelFormatEnum format = SDL_PIXELFORMAT_RGBA32;
    SDL_Surface* surface = SDL_CreateSurface(width, height, format);

    if (!surface) {
        SDL_Log("Failed to create surface: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_FillSurfaceRect(surface, NULL, SDL_MapRGBA(surface->format, 255, 0, 0, 255));
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FRect dst_rect = {100.0f, 150.0f, surface->w, surface->h};
    
    // int width, height;
    // SDL_GetRenderOutputSize(renderer, &width, &height);
    // SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);

    // SDL_FRect traffic_light;
    // traffic_light.w = traffic_light.h = traffic_light.y = 100;
    // traffic_light.x = (width - traffic_light.w) / 2;
    // SDL_RenderFillRect(renderer, &traffic_light);
}
