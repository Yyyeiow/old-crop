#include "Phase_stage2Ending.h"

Phase_stage2Ending::Phase_stage2Ending() {
    // ��� �ؽ���
    SDL_Surface* temp_sheet_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    winEnding_texture = SDL_CreateTextureFromSurface(g_renderer, temp_sheet_surface);
    SDL_FreeSurface(temp_sheet_surface);//���� �ʼ�

    temp_sheet_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    loseEnding_texture = SDL_CreateTextureFromSurface(g_renderer, temp_sheet_surface);
    SDL_FreeSurface(temp_sheet_surface);//���� �ʼ�

    ending_destination.x = 0;
    ending_destination.y = 0;
    ending_destination.w = screenWidth;
    ending_destination.h = screenHeight;

    // ��ư �ؽ���
    SDL_Surface* tmp_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    retry_button_texture = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
    if (retry_button_texture == NULL)
        std::cout << "retry_button_texture is NULL\n" << std::endl;
    SDL_FreeSurface(tmp_surface);
    retry_button_destination.x = 100;
    retry_button_destination.y = 100;
    retry_button_destination.w = 100;
    retry_button_destination.h = 50;

    tmp_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    home_button_texture = SDL_CreateTextureFromSurface(g_renderer, tmp_surface);
    SDL_FreeSurface(tmp_surface);
    // ��ư �ؽ����� ������ �Ķ������� ����
    home_button_destination.x = retry_button_destination.x;
    home_button_destination.y = retry_button_destination.y + 80;
    home_button_destination.w = 100;
    home_button_destination.h = 50;


    button = false;
    endingPhaseStartTime = SDL_GetTicks();;
    buttonPushed = 0; //0�̸� ��ư �ȴ���, 1�̸� retry��ư ����, 2�̸� home��ư ����
    pageCheck = 0;
}

void Phase_stage2Ending::HandleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {

        case SDL_QUIT:
            g_flag_running = false;
            break;

        case SDL_MOUSEBUTTONDOWN:
            if (event.button.button == SDL_BUTTON_LEFT)
                if (button) {//��ư�� ���������� ��ư�� ������ ����

                    int mouse_x = event.button.x;
                    int mouse_y = event.button.y;

                    if (mouse_x >= retry_button_destination.x && mouse_x <= retry_button_destination.x + retry_button_destination.w &&
                        mouse_y >= retry_button_destination.y && mouse_y <= retry_button_destination.y + retry_button_destination.h
                        )
                        buttonPushed = 1;
                    else if (mouse_x >= home_button_destination.x && mouse_x <= home_button_destination.x + home_button_destination.w &&
                        mouse_y >= home_button_destination.y && mouse_y <= home_button_destination.y + home_button_destination.h
                        )
                        buttonPushed = 2;
                }

            break;
        case SDL_KEYDOWN:
            if (event.key.keysym.sym == SDLK_SPACE) {
                pageCheck++;
                std::cout << "menu" << std::endl;
                endingPhaseStartTime = SDL_GetTicks();
            }
            break;
        }
    }
}

void Phase_stage2Ending::Update() {
    if (g_prev_game_phase != g_current_game_phase)
        endingPhaseStartTime = SDL_GetTicks();

    int currentTime = SDL_GetTicks();
    if (currentTime - endingPhaseStartTime > 3000) { // 3�ʰ� �����ٸ�
        // ��ư ���̰� ��
        button = true;
    }
    else
        button = false;

    if (game_result == 5) {
        pageCheck = 1;

    }
    if (pageCheck == 3) {
        g_current_game_phase = PHASE_INTRO;
        game_result = 0;
    }


    if (buttonPushed == 1) {
        g_current_game_phase = PHASE_STAGE;
        game_result = 0;
    }
    else if (buttonPushed == 2) {
        g_current_game_phase = PHASE_INTRO;
        game_result = 0;
    }


}


void Phase_stage2Ending::Render() {
    if (game_result == 1 || pageCheck == 1)
        SDL_RenderCopy(g_renderer, winEnding_texture, NULL, &ending_destination);
    else if (game_result == 2 || pageCheck == 2)
        SDL_RenderCopy(g_renderer, loseEnding_texture, NULL, &ending_destination);



    if (button) {

        SDL_RenderCopy(g_renderer, retry_button_texture, NULL, &retry_button_destination);
        SDL_RenderCopy(g_renderer, home_button_texture, NULL, &home_button_destination);

    }

    SDL_RenderPresent(g_renderer);
}

void Phase_stage2Ending::Reset() {
    button = false;
    buttonPushed = 0; //0�̸� ��ư �ȴ���, 1�̸� retry��ư ����, 2�̸� home��ư ����
    pageCheck = 0;
    endingPhaseStartTime = 0;
}

Phase_stage2Ending::~Phase_stage2Ending() {
    SDL_DestroyTexture(winEnding_texture);
    SDL_DestroyTexture(loseEnding_texture);
    SDL_DestroyTexture(retry_button_texture);
    SDL_DestroyTexture(home_button_texture);


}


