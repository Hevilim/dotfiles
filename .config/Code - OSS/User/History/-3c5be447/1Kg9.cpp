#include "../include/traffic_light.hpp"

void RenderTrafficLight(SDL_Renderer *renderer) {
    int width, height;
    SDL_GetRenderOutputSize(renderer, &width, &height);
    SDL_SetRenderDrawColor(renderer, 24, 24, 24, 255);
    SDL_FRect traffic_light;
    traffic_light.x = retraffic_lightct.y = 100;
    traffic_light.w = (width + traffic_light.x) / 2;
    traffic_light.h = (height + rect.y) / 2;
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderClear(renderer);
}
