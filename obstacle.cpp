#include "obstacle.h"
#include <iostream>
#include "mylib.h"
#include <cstdlib>
#include <ctime>

Obstacle::Obstacle() : texture(nullptr), speed(8.0f), bird(nullptr),
cactusCount(0), cactusUntilBird(4 + std::rand() % 3), positionX(800.0f) {
    rect = { static_cast<int>(positionX), 286, 64, 64 }; // cactus nằm sát đất
}

void Obstacle::Init(SDL_Renderer* renderer) {
    texture = LoadTexture("Images/cactus.png", renderer);
}

void Obstacle::SetBird(Bird* b) {
    bird = b;
}

void Obstacle::Update(float speedMultiplier) {
    positionX -= speed * speedMultiplier;
    rect.x = static_cast<int>(positionX);

    if (rect.x + rect.w < 0) {
        positionX = 800.0f;
        rect.x = static_cast<int>(positionX);

        cactusCount++;

        if (bird != nullptr && cactusCount >= cactusUntilBird) {
            bird->SetSpawnX(rect.x + 400);
            cactusCount = 0;
            cactusUntilBird = 4 + std::rand() % 3;
            std::cout << "[INFO] Bird will appear after cactus #" << cactusUntilBird << std::endl;
        }
    }
}

void Obstacle::Render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

SDL_Rect Obstacle::GetRect() {
    return rect;
}


