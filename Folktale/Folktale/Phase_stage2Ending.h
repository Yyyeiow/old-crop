#pragma once
#pragma once
#include "STAGE2.h"
#include <string>
#define GRID 40



class Phase_stage2Ending : public PhaseInterface {
private:
    //���� �ؽ���
    SDL_Texture* winEnding_texture;
    SDL_Texture* loseEnding_texture;
    SDL_Rect ending_destination;
    //��ư �ؽ�Ʈ �ؽ���
    SDL_Texture* retry_button_texture;
    SDL_Texture* home_button_texture;
    SDL_Rect retry_button_destination;
    SDL_Rect home_button_destination;

    // ���� ������� �Ѿ�� �ð��� �����ϴ� ����
    int endingPhaseStartTime;
    bool button; //��ư ���� ����

    int buttonPushed;//1�̸� retry��ư =>intro�� �̵� , 2�� home ��ư main���� �̵�

    TTF_Font* font = TTF_OpenFont("../../Resource/establish Retrosans.ttf", 100);

    int pageCheck;
public:
    Phase_stage2Ending();
    ~Phase_stage2Ending();

    void HandleEvents();
    void Update();
    void Render();
    void Reset();
};