#pragma once
#include <SDL.h>
#include "Creature_stage2.h"
#include "STAGE2.h"

extern SDL_Renderer* g_renderer;
extern SDL_Window* g_window;
extern bool g_flag_running;


class Stage2 : public PhaseInterface {
public:
    Stage2();
    ~Stage2();

    void HandleEvents();
    void Update();
    void Render();
    void Reset();


    

private:
    Turtle* turtle;
    Rabbit* rabbit;
    Coral* coral;
    Coral2* coral2;
    Conch* conch1;
    Conch* conch2 ;


    // ����Ű ���� ������
    bool f_list[4];
    int f_state; // ���� ���� Ű ����
    bool stop; // ���� ����

    //���� Ȯ�� ����
    SDL_RendererFlip flip;

    //�̷�
  
    int rabbitSpawnTimer;
    int coral2_spawn_timer; // coral2�� ��Ÿ���� ������� �ð��� �����ϴ� Ÿ�̸�
    bool coral2_visible;
    //�ƹ�Ű�� ������ ����
    int stage2_status; //0�̸� Ű ��� ����, 1�̸� ���� ��, 2�� ���� �Ͻ�����
    int alpha;
    
    //�ؽ���
    SDL_Texture* stage2_bg_texture;
    SDL_Texture* turtle_texture;
    SDL_Texture* rabbit_texture;
    SDL_Texture* coral_texture;
    SDL_Texture* coral2_texture;
    SDL_Texture* gan_texture;
    SDL_Texture* heart0_texture;
    SDL_Texture* heart2_texture;
    SDL_Texture* stage2_bgbgbg_texture;
    SDL_Texture* conch_texture;


    //�ؽ��� �簢��
    SDL_Rect turtle_destination_rect;
    SDL_Rect rabbit_destination_rect;
    SDL_Rect coral_destination_rect;
    SDL_Rect coral2_destination_rect;
    SDL_Rect stage2_bg_destination_rect;
    SDL_Rect gan_destination_rect;
    SDL_Rect heart0_destination_rect;
    SDL_Rect heart2_destination_rect;
    SDL_Rect stage2_bgbgbg_destination_rect;

    SDL_Rect conch_destination_rect;

};

