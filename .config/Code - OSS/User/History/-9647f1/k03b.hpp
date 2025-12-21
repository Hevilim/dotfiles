#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <string>

class Picture {
public:
    Picture(SDL_Renderer* renderer, const std::string& path);
    ~Picture();

    void RenderPicture(SDL_Renderer* renderer, int window_w, int window_h);

private:
    SDL_Texture* texture = nullptr;
    int picture_w = 0;
    int picture_h = 0;
};