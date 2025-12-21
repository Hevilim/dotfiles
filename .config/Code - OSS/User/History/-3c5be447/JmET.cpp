#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
    SDL_FRect traffic_light;
    rect.x = rect.y = 100;
    rect.w = (width + rect.x) / 2;
    rect.h = (height + rect.y) / 2;
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderClear(renderer);
}
