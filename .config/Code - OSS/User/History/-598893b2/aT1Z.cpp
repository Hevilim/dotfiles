#include "../include/space.hpp"

void RenderSpace(SDL_Renderer *renderer, SDL_Window *window;) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    int width, height;
    SDL_GetWindowSize(window, &width, &height);
    SDL_RenderLine(renderer, width/2, 0, x2, y2);
}
