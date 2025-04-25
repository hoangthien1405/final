#pragma once
#include <SDL.h>

class Bird {
public:
    Bird();
    void Init(SDL_Renderer* renderer);
    void Update(float speedMultiplier = 1.0f);
    void Render(SDL_Renderer* renderer);
    SDL_Rect GetRect();

    void SetSpawnX(int x); // Cài vị trí spawn khi cactus xuất hiện

private:
    SDL_Texture* texture;
    SDL_Rect rect;
    float speed;
    float positionX;
    bool isActive;
    int spawnX;
};



