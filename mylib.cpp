#include "mylib.h"
#include <iostream>

SDL_Texture* LoadTexture(const std::string& path, SDL_Renderer* renderer) {
    SDL_Surface* tempSurface = IMG_Load(path.c_str());
    if (!tempSurface) {
        std::cout << "Failed to load image: " << path << " - " << IMG_GetError() << std::endl;
        return nullptr;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
    SDL_FreeSurface(tempSurface);
    return texture;
}

TTF_Font* LoadFont(const std::string& path, int fontSize, SDL_Renderer* renderer) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), fontSize);
    if (!font) {
        std::cout << "Failed to load font: " << path << " - " << TTF_GetError() << std::endl;
    }
    return font;
}

SDL_Texture* RenderText(const std::string& message, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer) {
    SDL_Surface* surface = TTF_RenderText_Blended(font, message.c_str(), color);
    if (!surface) return nullptr;

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}
