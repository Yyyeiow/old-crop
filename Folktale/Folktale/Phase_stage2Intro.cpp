#include "Phase_stage2Intro.h"

Phase_stage2Intro::Phase_stage2Intro() {
    // ��� �ؽ���
    SDL_Surface* temp_sheet_surface;

    bg_destination.x = 0;
    bg_destination.y = 0;
    bg_destination.w = screenWidth;
    bg_destination.h = screenHeight;

    temp_sheet_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    first_intro_texture = SDL_CreateTextureFromSurface(g_renderer, temp_sheet_surface);
    SDL_FreeSurface(temp_sheet_surface);//���� �ʼ�

    temp_sheet_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    second_intro_texture = SDL_CreateTextureFromSurface(g_renderer, temp_sheet_surface);
    SDL_FreeSurface(temp_sheet_surface);//���� �ʼ�

    temp_sheet_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    third_intro_texture = SDL_CreateTextureFromSurface(g_renderer, temp_sheet_surface);
    SDL_FreeSurface(temp_sheet_surface);//���� �ʼ�

    bg_texture = first_intro_texture;
    count = 0; //0,1,2 ��� �̹��� ����� ��

}

void Phase_stage2Intro::HandleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_QUIT:
            g_flag_running = false;
            break;

        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE)
                count++;
            break;
        }
    }
}

void Phase_stage2Intro::Update() {
    if (count == 3) //3�� �� ������ ���������� ��ȯ
        g_current_game_phase = PHASE_STAGE;
}

void Phase_stage2Intro::Render() {
    if (count == 0) {
        bg_texture = first_intro_texture;
    }
    else if (count == 1) {
        bg_texture = second_intro_texture;
    }
    else if (count == 2) {
        bg_texture = third_intro_texture;
    }
    SDL_RenderCopy(g_renderer, bg_texture, NULL, &bg_destination);
    SDL_RenderPresent(g_renderer);
}

void Phase_stage2Intro::Reset() {
    count = 0;
    bg_texture = first_intro_texture;
}

Phase_stage2Intro::~Phase_stage2Intro() {
    SDL_DestroyTexture(bg_texture);
    SDL_DestroyTexture(first_intro_texture);
    SDL_DestroyTexture(second_intro_texture);
    SDL_DestroyTexture(third_intro_texture);

}