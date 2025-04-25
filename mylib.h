#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>

SDL_Texture* LoadTexture(const std::string& path, SDL_Renderer* renderer);//comment
TTF_Font* LoadFont(const std::string& path, int fontSize, SDL_Renderer* renderer);
SDL_Texture* RenderText(const std::string& message, TTF_Font* font, SDL_Color color, SDL_Renderer* renderer);

