#include<iostream>
#include "Phase_stage2Game.h"
#include "Phase_stage2Intro.h"
#include "Phase_stage2Ending.h"
#include "STAGE2.h"

SDL_Window* g_window;
SDL_Renderer* g_renderer;
bool g_flag_running;
Uint32 g_last_time_ms;
int screenWidth, screenHeight;
int g_current_game_phase;
int g_prev_game_phase;
int game_result = 0;

int main(int argc, char* argv[]) {
	SDL_Init(SDL_INIT_EVERYTHING);

	Uint32 cur_time_ms = SDL_GetTicks();
	// Initializing SDL library
	g_window = SDL_CreateWindow("STAGE2", 100, 100, 1080, 720, 0);


	g_renderer = SDL_CreateRenderer(g_window, -1, 0);
	
	g_flag_running = true;

	Stage2* stage2 = new Stage2();

	g_last_time_ms = SDL_GetTicks();

	PhaseInterface* game_phases[3];

	game_phases[0] = new Phase_stage2Intro;
	game_phases[1] = new Stage2;
	game_phases[2] = new Phase_stage2Ending;

	while (g_flag_running) {

        Uint32 cur_time_ms = SDL_GetTicks();


        // 게임 로직 업데이트 부분
        int currentTime = SDL_GetTicks();
        if (currentTime - g_last_time_ms < 33) {
            continue;
        }
        if (g_prev_game_phase != g_current_game_phase) {
            game_phases[g_prev_game_phase]->Reset();
        }
        g_prev_game_phase = g_current_game_phase;
        game_phases[g_current_game_phase]->HandleEvents();
        game_phases[g_current_game_phase]->Update();
        game_phases[g_current_game_phase]->Render();

        g_last_time_ms = cur_time_ms;


    }

    delete game_phases[0];
    delete game_phases[1];
    delete game_phases[2];


    SDL_DestroyRenderer(g_renderer);
    SDL_DestroyWindow(g_window);
    Mix_CloseAudio();
    SDL_Quit();
    
	return 0;
}