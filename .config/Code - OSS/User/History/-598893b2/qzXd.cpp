#include "../include/space.hpp"

void RenderSpace(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    int width, height;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_GetRenderOutputSize(renderer, &width, &height);
    // SDL_RenderLine(renderer, width / 2, 0, width / 2, height);

    for (int i = 0; i < width; i += 100) {
        SDL_RenderLine(renderer, width - i, 0, width - i, height);
        SDL_RenderLine(renderer, 0, height - i, width, height - i);
    }

}
