#pragma once
#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include <string>

class Picture {
public:
    Picture(SDL_Renderer* renderer, const std::string& path);
    ~Picture();

    void RenderPicture(SDL_Renderer* renderer, int windowWidth, int windowHeight);

private:
    SDL_Texture* texture = nullptr;
    int width = 0;
    int height = 0;
};