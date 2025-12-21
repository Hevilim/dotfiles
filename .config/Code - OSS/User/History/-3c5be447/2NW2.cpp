#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    SDL_PixelFormatEnum format = SDL_PIXELFORMAT_RGBA32;
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);

    SDL_FRect traffic_light;
    traffic_light.w = traffic_light.h = traffic_light.y = 100;
    traffic_light.x = (width - traffic_light.w) / 2;
    SDL_RenderFillRect(renderer, &traffic_light);
}
