#include "bird.h"
#include "mylib.h"
#include <iostream>

Bird::Bird() : texture(nullptr), speed(5.0f), isActive(false), spawnX(800), positionX(800.0f) {
    rect = { spawnX, 200, 64, 64 }; // Chim bay cao ở y = 200
}

void Bird::Init(SDL_Renderer* renderer) {
    texture = LoadTexture("Images/bird.png", renderer);
    if (!texture) {
        std::cout << "[ERROR] Failed to load bird.jpg: " << IMG_GetError() << std::endl;
    }
}

void Bird::SetSpawnX(int x) {
    spawnX = x;
    positionX = static_cast<float>(x);
    rect.x = x;
    rect.y = 200;  // Bay cao một chút
    isActive = true;
    std::cout << "[SPAWN] Bird spawned at x = " << spawnX << std::endl;
}

void Bird::Update(float speedMultiplier) {
    if (isActive) {
        positionX -= speed * speedMultiplier;
        rect.x = static_cast<int>(positionX);
    }
}

void Bird::Render(SDL_Renderer* renderer) {
    if (isActive) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

SDL_Rect Bird::GetRect() {
    return rect;
}


