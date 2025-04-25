#pragma once
#include <SDL.h>
#include "bird.h"

class Obstacle {
public:
    Obstacle();
    void Init(SDL_Renderer* renderer);
    void Update(float speedMultiplier = 1.0f);
    void Render(SDL_Renderer* renderer);
    SDL_Rect GetRect();

    void SetBird(Bird* b); // Kết nối chim với cactus

private:
    SDL_Texture* texture;
    SDL_Rect rect;
    float speed;
    float positionX;

    Bird* bird;
    int cactusCount;        // Đếm số lần cactus reset
    int cactusUntilBird;    // Bao nhiêu cây nữa thì spawn chim
};

