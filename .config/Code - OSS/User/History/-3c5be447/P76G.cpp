#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer, SDL_Window *window) {
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    SDL_FRect* traffic_light = {100, 100, width + 100 / 2, height + 100 / 2}; 
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
    SDL_RenderRect(renderer, &traffic_light);
}
