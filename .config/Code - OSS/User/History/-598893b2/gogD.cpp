#include "../include/space.hpp"

void RenderSpace(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_RenderLine(renderer, x1, y1, x2, y2);
}
