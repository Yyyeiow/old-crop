#pragma once

#include "Creature_stage3.h"

extern bool g_flag_running;
extern SDL_Window* g_window;
extern SDL_Renderer* g_renderer;

extern int screenWidth, screenHeight;

class Stage3
{
private:
    Bell* bell;
    Magpie* magpie;
    Snake* snake;
	Bomb* bomb;
	
	//방향키 조작 변수들
	bool f_list[4];
	int f_state;//현재 눌린 키 정보
	bool stop;//정지 정보

	//승패 확인 변수
	int game_result;

	SDL_RendererFlip flip;

public:
	Stage3();
	~Stage3();

	void HandleEvents();
	void Update();
	void Render();
	void Reset();

	int getResult() {
		return this->game_result;
	}

private:
	//종 텍스쳐 
	SDL_Texture* bell_texture; // the SDL_Texture 
	SDL_Rect bell_destination_rect; // for destination
	//까치 텍스쳐
	SDL_Texture* magpie_texture; // the SDL_Texture 
	SDL_Rect magpie_destination_rect; // for destination
	//구렁이 텍스쳐
	SDL_Texture* snakeHead_texture; // the SDL_Texture 
	SDL_Texture* snakeBody_texture;
	SDL_Texture* snakeTail_texture;
	SDL_Rect snake_destination_rect; // for destination

	//배경 텍스쳐
	SDL_Texture* bg_texture; // the SDL_Texture 
	SDL_Rect bg_destination_rect; // for destination

	//폭탄 텍스쳐
	SDL_Texture* bombAfter_texture;
	SDL_Rect bomb_source_rect; // for destination
	SDL_Rect bomb_destination_rect;

	//하트 텍스쳐
	SDL_Texture* heartZero_texture; // the SDL_Texture 
	SDL_Texture* heartHalf_texture; // the SDL_Texture 
	SDL_Texture* heartOne_texture; // the SDL_Texture 
	SDL_Rect heart_destination_rect; // for destination
};