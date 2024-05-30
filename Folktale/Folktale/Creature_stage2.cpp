#include "Creature_stage2.h"
#include "Phase_stage2Game.h"

default_random_engine generator;

//�̷�----------------------------------------------------------------------------------------------------------------


int Maze::maze[SCREEN_HEIGHT][SCREEN_WIDTH] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1} ,
	{1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 1, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 2, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 1, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 1},
	{1, 2, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 2, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
}; // maze �迭 �ܺ� ����

bool Maze::isCoral(int x, int y) {
	return maze[y][x] == 1;
}

//��ȣ----------------------------------------------------------------------------------------------------------------
Coral::Coral(int x, int y, int speed, double health, int attackPower): Ally( x, y,  speed,  health,attackPower){
	
}

void Coral::Draw() {
}

void Coral::attackDamage(int attackPower) {
	 
}

void Coral::move(int newX, int newY) {
}

void Coral::GetAttackted(int damage) {

}

Coral::~Coral() {
}

//��ȣ2----------------------------------------------------------------------------------------------------------------
Coral2::Coral2(int x, int y, int speed, double health, int attackPower) : Ally(x, y, speed, health, attackPower) {
	
}


void Coral2::Draw() {
}

void Coral2::attackDamage(int attackPower) {

}

void Coral2::move(int newX, int newY) {
}

void Coral2::GetAttackted(int damage) {

}
Coral2::~Coral2() {
}

//�Ҷ��----------------------------------------------------------------------------------------------------------------

Conch::Conch(int x, int y, int speed, double health, int attackPower, int tX, int tY) : Monster(x, y, speed, health, attackPower, tX, tY) {//init �Լ� -> �ʱⰪ ����
	

	moveCounter = 0;

}

void Conch::Draw() {

}

void Conch::GetAttackted(int damage) {
	
}


void Conch::move(int newX, int newY) {
	// ������ ī���͸� ������Ŵ
	moveCounter++;

	// ������ ī���Ͱ� ���� ���� �����ϸ� �������� �����ϰ� ī���͸� ����
	if (moveCounter >= MOVE_DELAY) {
		int x = getX();
		int y = getY();

		// �����ϰ� ���� ����
		direction = rand() % 4;

		// ���õ� ���⿡ ���� �̵�
		switch (direction) {
		case 0: // ��
			y--;
			break;
		case 1: // ��
			y++;
			break;
		case 2: // ��
			x--;
			break;
		case 3: // ��
			x++;
			break;
		}

		// ���� ��踦 ����� �ݴ� �������� �̵�
		if (x < 0) {
			x = 0;
			direction = 3; // ��� ���� ����
		}
		else if (x >= SCREEN_WIDTH) {
			x = SCREEN_WIDTH - 1;
			direction = 2; // �·� ���� ����
		}
		if (y < 0) {
			y = 0;
			direction = 1; // �Ϸ� ���� ����
		}
		else if (y >= SCREEN_HEIGHT) {
			y = SCREEN_HEIGHT - 1;
			direction = 0; // ������ ���� ����
		}

		// ��ġ ������Ʈ
		setXY(x, y);

		// ������ ī���� ����
		moveCounter = 0;
	}
}

void Conch::attackDamage(int attackPower) {
	

}


Conch::~Conch() {
	
}


//�ź���----------------------------------------------------------------------------------------------------------------
Turtle::Turtle(int x, int y, int speed, double health, int attackPower):Ally(x,  y,  speed,  health,  attackPower), turtle_invincible(false), invincible_timer(0), invincible_duration(180) {
	//������
	
	T_output = '*';
}

void Turtle::Draw() {
	
}

//�ź��̰� ���ݹ޾�����
void Turtle::GetAttackted(int damage) {
	if (!isInvincible()) { // ���� ���°� �ƴ� ���� ���ظ� ����
		cout << "�ź��̰� ���ݹ޾ҽ��ϴ�." << endl;
		int hp = getHealth();
		hp -= damage;
		if (hp <= 0) {
			hp = 0; // �ź��� ����
		}
		setHealth(hp);
		setInvincible(true); // ���� ���·� ����
		setInvincibleTimer(invincible_duration); // Ÿ�̸� ����
	}
}

// �ź��� �̵� �޼���
void Turtle::move(int newX, int newY) {
	// ���ο� ��ġ�� �̷� ��� ���� �ִ��� Ȯ��
	if (newX >= 0 && newX < SCREEN_WIDTH && newY >= 0 && newY < SCREEN_HEIGHT) {
		// ���ο� ��ġ�� ��ȣ���� Ȯ��
		if (Maze::isCoral(newX, newY)) {
			// ��ȣ�� �ε������Ƿ� ���ظ� �ް� �̵����� ����
			this->GetAttackted(1);
		}
		else {
			// ��ȣ�� �ƴ϶�� �ź��̸� ���ο� ��ġ�� �̵�
			this->setXY(newX, newY);
		}
	}
}
	



void Turtle::attackDamage(int attackPower) {
}

bool Turtle::isCollision_Coral(Coral* coral) {
	bool isCollision = false;//�浹����
	//�ź��̿� ��ȣ�� ��ǥ�� ������ �浹
	if (this->getX() == coral->getX() && this->getY() == coral->getY()) {
		isCollision = true;

	}
	return isCollision;
	
}
bool Turtle::isCollision_Coral2(Coral2* coral2) {
	bool isCollision = false;//�浹����
	//�ź��̿� ��ȣ�� ��ǥ�� ������ �浹
	if (this->getX() == coral2->getX() && this->getY() == coral2->getY()) {
		isCollision = true;

	}
	return isCollision;

}
bool Turtle::isCollision_Rabbit(Rabbit* rabbit) {
	bool isCollision = false;//�浹����
	//�ź��̿� �䳢�� ��ǥ�� ������ �浹
	if (this->getX() == rabbit->getX() && this->getY() == rabbit->getY()) {
		isCollision = true;
		// setIsFace �޼��� ȣ��
		rabbit->setIsFace(!rabbit->getIsFace());
	}
	return isCollision;
}

bool Turtle::isCollision_Conch(Conch* Conch) {
	bool isCollision = false;//�浹����
	//�ź��̿� �Ҷ���� ��ǥ�� ������ �浹
	if (this->getX() == Conch->getX() && this->getY() == Conch->getY()) {
		isCollision = true;
	}
	return isCollision;
}

char Turtle::get_output() {
	return this->T_output;
}

//�Ҹ�������
Turtle::~Turtle() {}

//�䳢----------------------------------------------------------------------------------------------------------------
Rabbit::Rabbit(int x, int y, int speed, double health) : bellAndRabbit(x, y, speed, health) {
	R_output = '^';
}

void Rabbit::Draw() {
}

void Rabbit::GetAttackted(int damage) {
}

void Rabbit::move(int newX, int newY) {
}
void Rabbit::spawn() {
	// ������ �� �ִ� ��ġ ��� ����
	int rabbitSpawnTimer ;
	std::vector<std::pair<int, int>> validPositions;

	for (int y = 0; y < SCREEN_HEIGHT; ++y) {
		for (int x = 0; x < SCREEN_WIDTH; ++x) {
			if (Maze::maze[y][x] == 0) { // ��ȣ�� �ƴ� ��ġ Ȯ��
				validPositions.push_back(std::make_pair(x, y));
			}
		}
	}

	if (!validPositions.empty()) {
		// �������� ��ȿ�� ��ġ ����
		std::uniform_int_distribution<int> distribution(0, validPositions.size() - 1);
		int index = distribution(generator);
		this->setXY(validPositions[index].first, validPositions[index].second);
	}


}
char Rabbit::get_output() {
	return this->R_output;
}

Rabbit::~Rabbit() {}
