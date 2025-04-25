#pragma once
#include <SDL.h>

class Heart {
public:
    Heart();
    void Init(SDL_Renderer* renderer);
    void Update();
    void Render(SDL_Renderer* renderer);
    SDL_Rect GetRect();
    void Reset();

    bool isActive;

private:
    SDL_Texture* texture;
    SDL_Rect rect;
    int speed;
    Uint32 lastSpawnTime;
    Uint32 spawnDelay;
};


