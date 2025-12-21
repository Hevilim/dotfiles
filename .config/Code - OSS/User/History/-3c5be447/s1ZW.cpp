#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
    SDL_FRect traffic_light;
    traffic_light.x = traffic_light.y = 100;
    traffic_light.w = (width + traffic_light.x) / 2;
    traffic_light.h = (height + traffic_light.y) / 2;
    SDL_RenderFillRect(renderer, &traffic_light);
    SDL_RenderClear(renderer);
}
