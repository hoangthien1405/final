#pragma once
#include <SDL.h>

class Dino {
public:
    Dino();
    void Init(SDL_Renderer* renderer);
    void Update();
    void Render(SDL_Renderer* renderer);
    void HandleEvent(SDL_Event& e);
    SDL_Rect GetRect();
    void TriggerHitEffect();      // ✅ hiệu ứng khi va chạm
    bool IsSlowed();              // ✅ kiểm tra đang bị chậm
    void Reset();                 // ✅ reset trạng thái

private:
    SDL_Texture* texture;
    SDL_Rect rect;
    int velocityY;
    bool isJumping;

    // Hiệu ứng bị va chạm
    bool isBlinking;
    Uint32 blinkStartTime;
    bool slowed;
    Uint32 slowStartTime;
};
