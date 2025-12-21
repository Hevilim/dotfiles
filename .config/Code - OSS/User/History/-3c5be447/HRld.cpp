#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
    SDL_FRect traffic_light;
    
    SDL_RenderFillRect(renderer, width / 2, height / 2, 100, 100);
    SDL_RenderClear(renderer);
}
