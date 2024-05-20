#pragma once
#include "Creature.h"
#include <list>
#include <random>
#include <iostream>
#define SNAKESIZE 15
#define GRID 30

using namespace std;

//ui 적용 시 값 얻어와서 할당하기
//여기서 정의한 전역 변수는 phase_stage3, main에서 사용 가능
enum DIRECTION { LEFT, RIGHT, UP, DOWN, STOP };

extern int screenWidth;
extern int screenHeight;


//일단 각 객체별 output 설정
//구렁이 -> #
//까치 -> *
//종 -> @


//구렁이 연결리스트 노드
typedef struct Node {
	//x좌표 y좌표
	int sX, sY;
	int dircetion;
}Node;


//구렁이
class Snake : public Monster  //구렁이
{
private:
	//구렁이 좌표를 저장하고 업데이트 할 연결리스트
	list<Node*> snakeList;
    DIRECTION dSnake;
	int moveCounter;

public:
	Snake(int x, int y, int speed, double health, int attackPower, int tX, int tY);
	~Snake();
	virtual void Draw();
	virtual void GetAttackted(int damage);
	virtual void move(int newX, int newY);
	virtual void attackDamage(int attackPower);
	bool isNodeInList(int x, int y);

	//getter setter
	list<Node*> getSnakeList() {
		return snakeList;
	}
	DIRECTION getSnakeDirection() {
		return dSnake;
	}

};

//폭탄
typedef struct bombAttack {
	int x;
	int y;
}bombAttack;

class Bomb : public Monster  
{
private:
	char bb_output; //이게 출력되면 실제로 데미지 가격
	char bb_out_prev; //실제로 떨어지기 3프레임 전에 출력할 것
	int checkCount;
	bombAttack bombRange[9];
public:
	Bomb(int x, int y, int speed, double health, int attackPower, int tX, int tY);
	~Bomb();
	virtual void Draw();
	virtual void GetAttackted(int damage);
	virtual void move(int newX, int newY);
	virtual void attackDamage(int attackPower);

	//getter setter
	char getOutputPrev() {
		return bb_out_prev;
	}
	char getOutput() {
		return bb_output;
	}
	int getCheckCount() {
		return checkCount;
	}
	void setCheckCount(int a) {
		this->checkCount = a;
	}

	bombAttack* getBombRange() {
		return bombRange;
	}
};



//종
class Bell : public bellAndRabbit
{
private:
    //부모 객체에 있는 필드만으로 사용
    char b_output;
public:
    Bell(int x, int y, int speed, double health);
    ~Bell();

    virtual void Draw();
    virtual void GetAttackted(int damage);
    virtual void move(int newX, int newY);
    virtual void spawn();
    char get_output();
};

//까치
class Magpie : public Ally
{
private:
    char m_output;
public:
	Magpie(int x, int y, int speed, double health, int attackPower);
	virtual void Draw();
	virtual void GetAttackted(int damage);
	virtual void move(int newX, int newY);
	virtual void attackDamage(int attackPower);

	//충돌 여부 확인
	bool isCollidingSnake(Snake* snake);
	bool isCollidingBell(Bell* bell);
	bool isCollidingBomb(Bomb* bomb);

    char get_output();
};


