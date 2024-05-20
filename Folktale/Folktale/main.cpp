#include<iostream>
#include "Phase_stage3.h"

/////////////////////////////////////////////////
// Declaration
SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;
int screenWidth, screenHeight;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    // Initializing SDL library
    g_window = SDL_CreateWindow("STAGE3", 100, 100, 600, 600, 0);
    g_renderer = SDL_CreateRenderer(g_window, -1, 0);
    SDL_GetWindowSize(g_window, &screenWidth, &screenHeight);//크기 지정


    g_flag_running = true;

    //stage객체 생성
    Stage3* stage3=new Stage3();

    g_last_time_ms = SDL_GetTicks();

    while (g_flag_running)
    {
        Uint32 cur_time_ms = SDL_GetTicks();

        if (cur_time_ms - g_last_time_ms < 50)
            continue;

        if (stage3->getResult() == 1|| stage3->getResult() == 2) { //승리로 게임 끝남
            g_flag_running = false;
        }

        stage3->HandleEvents();
        stage3->Update();
        stage3->Render();

        g_last_time_ms = cur_time_ms;
    }

    delete stage3;


    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    SDL_Quit();

    return 0;
}