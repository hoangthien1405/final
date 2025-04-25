#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include "dino.h"
#include "obstacle.h"
#include "bird.h"
#include "heart.h"

class Game {
public:
    Game();
    ~Game();
    bool Init();
    void Run();
    void Clean();

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
    Dino dino;
    Obstacle obstacle;
    Bird bird;
    Heart heart;

    SDL_Texture* skyTexture;
    SDL_Texture* groundTexture;
    SDL_Texture* gameOverTexture;
    SDL_Texture* startTexture;

    TTF_Font* font;

    bool isRunning;
    bool isGameOver;
    bool isInMenu;

    int heartsEaten;
    Uint32 lastHitTime;

    int level;
    Uint32 levelStartTime;
    float speedMultiplier;

    void ResetGame();
};

