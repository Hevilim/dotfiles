#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);

    SDL_FRect traffic_light;
    traffic_light.w = traffic_light.h = 100;
    traffic_light.x = (width + traffic_light.w) / 2;
    traffic_light.y = (height + traffic_light.h) / 2;
    SDL_RenderFillRect(renderer, &traffic_light);
}
