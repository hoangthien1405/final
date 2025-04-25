#include "game.h"
#include "mylib.h"
#include <SDL_image.h>
#include <iostream>

Game::Game()
    : window(nullptr), renderer(nullptr), isRunning(true),
    isGameOver(false), heartsEaten(0), lastHitTime(0),
    skyTexture(nullptr), groundTexture(nullptr), gameOverTexture(nullptr),
    level(1), levelStartTime(0), speedMultiplier(1.0f), isInMenu(true) {
}

Game::~Game() {
    Clean();
}

bool Game::Init() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) return false;

    window = SDL_CreateWindow("Dino Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 400, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window || !renderer) return false;

    dino.Init(renderer);
    obstacle.Init(renderer);
    bird.Init(renderer);
    heart.Init(renderer);

    obstacle.SetBird(&bird);

    skyTexture = LoadTexture("Images/sky.png", renderer);
    groundTexture = LoadTexture("Images/ground.png", renderer);
    gameOverTexture = LoadTexture("Images/gameover.png", renderer);

    level = 1;
    levelStartTime = SDL_GetTicks();
    speedMultiplier = 1.0f;
    isInMenu = true;

    if (TTF_Init() == -1) return false;
    font = LoadFont("Images/FFF_Tusj.ttf", 48, renderer);
    startTexture = LoadTexture("Images/start.png", renderer);

    return true;
}

void Game::Run() {
    SDL_Event event;
    while (isRunning) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) isRunning = false;

            if (isInMenu && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                isInMenu = false;
            }

            if (isGameOver && event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_RETURN) {
                ResetGame();
            }

            if (!isGameOver && !isInMenu) dino.HandleEvent(event);
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        if (isInMenu) {
            SDL_Rect skyRect = { 0, 0, 800, 336 };
            SDL_Rect groundRect = { 0, 336, 800, 64 };
            SDL_RenderCopy(renderer, skyTexture, NULL, &skyRect);
            SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);

            SDL_Color black = { 0, 0, 0, 255 };

            SDL_Texture* titleText = RenderText("DINO RUN", font, black, renderer);
            SDL_Rect titleRect = { 220, 60, 360, 80 };
            SDL_RenderCopy(renderer, titleText, NULL, &titleRect);
            SDL_DestroyTexture(titleText);

            // ✅ Vị trí nút đẹp: giữa màn hình, không đè mây hay cactus
            SDL_Rect startRect = { 310, 200, 180, 60 };
            SDL_RenderCopy(renderer, startTexture, NULL, &startRect);

            if (event.type == SDL_MOUSEBUTTONDOWN) {
                int x, y;
                SDL_GetMouseState(&x, &y);
                if (x >= startRect.x && x <= startRect.x + startRect.w &&
                    y >= startRect.y && y <= startRect.y + startRect.h) {
                    isInMenu = false;
                }
            }

            SDL_RenderPresent(renderer);
            SDL_Delay(16);
            continue;
        }

        Uint32 now = SDL_GetTicks();

        if (!isGameOver) {
            if (now - levelStartTime >= 20000) {
                level++;
                speedMultiplier += 0.2f;
                levelStartTime = now;
                std::cout << "[LEVEL UP] Level: " << level << " | Speed multiplier: " << speedMultiplier << std::endl;
            }

            dino.Update();
            obstacle.Update(speedMultiplier);
            bird.Update(speedMultiplier);
            heart.Update();
        }

        SDL_Rect skyRect = { 0, 0, 800, 350 };
        SDL_RenderCopy(renderer, skyTexture, NULL, &skyRect);
        SDL_Rect groundRect = { 0, 336, 800, 64 };
        SDL_RenderCopy(renderer, groundTexture, NULL, &groundRect);

        dino.Render(renderer);
        obstacle.Render(renderer);
        bird.Render(renderer);
        heart.Render(renderer);

        SDL_Rect dinoRect = dino.GetRect();
        SDL_Rect obsRect = obstacle.GetRect();
        SDL_Rect birdRect = bird.GetRect();
        SDL_Rect heartRect = heart.GetRect();

        SDL_Rect dinoHitBox = { dinoRect.x + 5, dinoRect.y + 5, dinoRect.w - 10, dinoRect.h - 10 };
        SDL_Rect cactusHitBox = { obsRect.x + 5, obsRect.y + 5, obsRect.w - 10, obsRect.h - 10 };
        SDL_Rect birdHitBox = { birdRect.x + 5, birdRect.y + 5, birdRect.w - 10, birdRect.h - 10 };

        if (!isGameOver && (SDL_HasIntersection(&dinoHitBox, &cactusHitBox) ||
            SDL_HasIntersection(&dinoHitBox, &birdHitBox)) &&
            now - lastHitTime >= 1500) {

            lastHitTime = now;
            if (heartsEaten > 0) {
                heartsEaten--;
                std::cout << "[HIT] Dino hit! Remaining hearts: " << heartsEaten << std::endl;
            }
            else {
                std::cout << "[END] Dino died. Game Over!" << std::endl;
                isGameOver = true;
            }
        }

        if (!isGameOver &&
            heart.isActive &&
            SDL_HasIntersection(&dinoRect, &heartRect) &&
            dinoRect.y < heartRect.y) {
            if (heartsEaten < 3) {
                heartsEaten++;
                heart.Reset();
                std::cout << "[HEART] Eaten! Total: " << heartsEaten << std::endl;
            }
        }

        if (isGameOver) {
            SDL_Rect overRect = { 250, 120, 300, 150 };
            SDL_RenderCopy(renderer, gameOverTexture, NULL, &overRect);
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    }
}

void Game::ResetGame() {
    heartsEaten = 0;
    lastHitTime = 0;
    isGameOver = false;

    level = 1;
    speedMultiplier = 1.0f;
    levelStartTime = SDL_GetTicks();
    isInMenu = true;

    dino = Dino();
    dino.Init(renderer);
    obstacle = Obstacle();
    obstacle.Init(renderer);
    bird = Bird();
    bird.Init(renderer);
    heart = Heart();
    heart.Init(renderer);
}

void Game::Clean() {
    SDL_DestroyTexture(startTexture);
    SDL_DestroyTexture(skyTexture);
    SDL_DestroyTexture(groundTexture);
    SDL_DestroyTexture(gameOverTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_CloseFont(font);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}





