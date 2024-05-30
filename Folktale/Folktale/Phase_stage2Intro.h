#pragma once
#pragma once

#include "STAGE2.h"
#define GRID 40


class Phase_stage2Intro : public PhaseInterface {
private:
    // 배경 텍스쳐
    SDL_Texture* bg_texture;
    SDL_Rect bg_destination;

    SDL_Texture* first_intro_texture;
    SDL_Texture* second_intro_texture;
    SDL_Texture* third_intro_texture;

    // SDL_Rect intro_destination;

    int count;

public:
    Phase_stage2Intro();
    ~Phase_stage2Intro();

    void HandleEvents();
    void Update();
    void Render();
    void Reset();
};