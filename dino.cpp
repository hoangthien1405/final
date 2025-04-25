#include "dino.h"
#include "mylib.h"

Dino::Dino() : texture(nullptr), velocityY(0), isJumping(false) {
    rect = { 50, 286, 64, 64 };  // ✅ chỉnh y = 285 để đứng khớp mặt đất, h = 50 cho bằng xương rồng
}

void Dino::Init(SDL_Renderer* renderer) {
    texture = LoadTexture("Images/dino.png", renderer);
}

void Dino::Update() {
    if (isJumping) {
        rect.y += velocityY;
        velocityY += 1;

        if (rect.y >= 285) {
            rect.y = 285;
            isJumping = false;
            velocityY = 0;
        }
    }
}

void Dino::Render(SDL_Renderer* renderer) {
    SDL_RenderCopy(renderer, texture, NULL, &rect);
}

void Dino::HandleEvent(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_SPACE && !isJumping) {
        isJumping = true;
        velocityY = -15;
    }
}

SDL_Rect Dino::GetRect() {
    return rect;
}

void Dino::Reset() {
    rect.y = 285;
    isJumping = false;
    velocityY = 0;
}

