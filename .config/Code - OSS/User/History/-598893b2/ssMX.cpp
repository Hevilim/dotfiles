#include "../include/space.hpp"

SDL_Color black = {0, 0, 0, 255};

void RenderSpace(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, black.r, black.g, black.b, black.a);
    SDL_RenderClear(renderer);
}
