#include "../include/space.hpp"

void RenderSpace(SDL_Renderer *renderer, SDL_Window *window) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    
    int window_w, window_h;
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_GetRenderOutputSize(renderer, &window_w, &window_h);
    // SDL_RenderLine(renderer, width / 2, 0, width / 2, height);

    for (int i = 0; i < width / 2; i += 100) {
        SDL_RenderLine(renderer, window_w / 2 - i, 0, window_w / 2 - i, window_h);
        SDL_RenderLine(renderer, window_w / 2 + i, 0, window_w / 2 + i, window_h);
    }

    for (int i = 0; i < height / 2; i += 100) {
        SDL_RenderLine(renderer, 0, window_h / 2 - i, window_w, window_h / 2 - i);
        SDL_RenderLine(renderer, 0, window_h / 2 + i, window_w, window_h / 2 + i);
    }


}
