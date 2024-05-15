#pragma once
#include <SDL.h>
#include "Creature_stage3.h"

extern bool g_flag_running;

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
};