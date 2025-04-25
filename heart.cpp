#include "heart.h"
#include "mylib.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

Heart::Heart() : texture(nullptr), speed(5), isActive(false),
lastSpawnTime(0), spawnDelay(3000 + std::rand() % 3000) {
    rect = { 800, 250, 40, 40 };
}

void Heart::Init(SDL_Renderer* renderer) {
    texture = LoadTexture("Images/heart.png", renderer);
    if (!texture) {
        std::cout << "[ERROR] Failed to load heart.png: " << IMG_GetError() << std::endl;
    }
    else {
        std::cout << "[INFO] Heart loaded successfully!" << std::endl;
    }
}

void Heart::Update() {
    Uint32 now = SDL_GetTicks();

    if (!isActive && now - lastSpawnTime >= spawnDelay) {
        rect.x = 800;
        rect.y = 250;
        isActive = true;
        std::cout << "[SPAWN] Heart appeared!" << std::endl;
    }

    if (isActive) {
        rect.x -= speed;

        if (rect.x + rect.w < 0) {
            Reset();
        }
    }
}

void Heart::Render(SDL_Renderer* renderer) {
    if (isActive) {
        std::cout << "[RENDER] Heart at x = " << rect.x << std::endl;
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

SDL_Rect Heart::GetRect() {
    return rect;
}

void Heart::Reset() {
    isActive = false;
    lastSpawnTime = SDL_GetTicks();
    spawnDelay = 3000 + std::rand() % 3000;
}
