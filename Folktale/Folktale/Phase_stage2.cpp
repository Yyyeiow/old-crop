#include "Phase_stage2Game.h"
#include <Windows.h>
#include <SDL_image.h> 
#include <iomanip>

using namespace std;

extern default_random_engine generator;


//�̷�

//��� �ؽ���

SDL_Rect stage2_bg_source_rect;

Stage2::Stage2() {
    
    uniform_int_distribution<int> distributionX(0, SCREEN_WIDTH);
    uniform_int_distribution<int> distributionY(0, SCREEN_HEIGHT);
    rabbit = new Rabbit(distributionX(generator), distributionY(generator), 1, 3);
    turtle = new Turtle(1, 1, 0 ,3 , 0);
    coral = new Coral(0, 0, 0, 0, 1);
    coral2 = new Coral2(0, 0, 0, 0, 1);
    // ���� Conch ��ü ����
    conch1 = new Conch(15, 15, 0 , 0, 1, 0, 0);
    conch2 = new Conch(10, 10, 0, 0, 1, 0, 0);

    rabbitSpawnTimer = RABBIT_SPAWN_TIME;
    coral2_spawn_timer = CORAL2_SPAWN_TIME; // CORAL2_SPAWN_TIME�� coral2�� ��Ÿ���� ������� �ð� ����
    coral2_visible = false; // ó������ coral2�� ǥ������ ����

    // ��� �ؽ��� �ε�
    SDL_Surface* stage2_bg_surface = IMG_Load("../../resources/stage2/stage2_bg.jpg");
    stage2_bg_texture = SDL_CreateTextureFromSurface(g_renderer, stage2_bg_surface);
    SDL_FreeSurface(stage2_bg_surface);
    stage2_bg_source_rect = { 0, 0, 500, 500 };
    stage2_bg_destination_rect = { TILE_SIZE,TILE_SIZE , 600, 600 };

    //����� �ؽ�ó �ε�
    SDL_Surface* stage2_bgbg_surface = IMG_Load("../../resources/stage2/stage2_bgbg.png");
    stage2_bgbgbg_texture = SDL_CreateTextureFromSurface(g_renderer, stage2_bgbg_surface);
    stage2_bgbgbg_destination_rect = { 0, 0, 1080, 720 };
    SDL_FreeSurface(stage2_bgbg_surface);


    //�ź��� �ؽ��� �ε�
    SDL_Surface*  turtle_surface = IMG_Load("../../resources/stage2/stage2_turtle.png");
    turtle_texture = SDL_CreateTextureFromSurface(g_renderer, turtle_surface);
    SDL_FreeSurface(turtle_surface);
    turtle_destination_rect.x = turtle->getX() * GRID_stage2;
    turtle_destination_rect.y = turtle->getY() * GRID_stage2;
    turtle_destination_rect.w = GRID_stage2;
    turtle_destination_rect.h = GRID_stage2;

    //�䳢 �ؽ��� �ε�
    SDL_Surface*  rabbit_surface = IMG_Load("../../resources/stage2/stage2_rabbit.png");
    rabbit_texture = SDL_CreateTextureFromSurface(g_renderer, rabbit_surface);
    SDL_FreeSurface(rabbit_surface);
    rabbit_destination_rect.x = rabbit->getX() * GRID_stage2;
    rabbit_destination_rect.y = rabbit->getY() * GRID_stage2;
    rabbit_destination_rect.w = GRID_stage2;
    rabbit_destination_rect.h = GRID_stage2;

    //��ȣ �ؽ��� �ε�
    SDL_Surface*  coral_surface = IMG_Load("../../resources/stage2/stage2_coral2.png");
    coral_texture = SDL_CreateTextureFromSurface(g_renderer, coral_surface);
    SDL_FreeSurface(coral_surface);
    coral_destination_rect.x = coral->getX() * GRID_stage2;
    coral_destination_rect.y = coral->getY() * GRID_stage2;
    coral_destination_rect.w = GRID_stage2;
    coral_destination_rect.h = GRID_stage2;

    //��ȣ2 �ؽ��� �ε�
    SDL_Surface*  coral2_surface = IMG_Load("../../resources/stage2/stage2_coral.png");
    coral2_texture = SDL_CreateTextureFromSurface(g_renderer, coral2_surface);
    SDL_FreeSurface(coral2_surface);
    coral2_destination_rect.x = coral->getX() * GRID_stage2;
    coral2_destination_rect.y = coral->getY() * GRID_stage2;
    coral2_destination_rect.w = GRID_stage2;
    coral2_destination_rect.h = GRID_stage2;


    //�� �ؽ��� �ε�
    SDL_Surface* gan_surface = IMG_Load("../../resources/stage2/stage2_gan.png");
    gan_texture = SDL_CreateTextureFromSurface(g_renderer, gan_surface);
    SDL_FreeSurface(gan_surface);
    gan_destination_rect.x = 0;
    gan_destination_rect.y = 0;
    gan_destination_rect.w = GRID_stage2*2;
    gan_destination_rect.h = GRID_stage2*2;

    //��Ʈ0 �ؽ��� �ε�
    SDL_Surface* heart0_surface = IMG_Load("../../resources/stage2/stage2_heart0.png");
    heart0_texture = SDL_CreateTextureFromSurface(g_renderer, heart0_surface);
    SDL_FreeSurface(heart0_surface);
    heart0_destination_rect.x = 0;
    heart0_destination_rect.y = 0;
    heart0_destination_rect.w = GRID_stage2*2;
    heart0_destination_rect.h = GRID_stage2*2;

    //��Ʈ2 �ؽ��� �ε�
    SDL_Surface* heart2_surface = IMG_Load("../../resources/stage2/stage2_heart2.png");
    heart2_texture = SDL_CreateTextureFromSurface(g_renderer, heart2_surface);
    SDL_FreeSurface(heart2_surface);
    heart2_destination_rect.x = 0;
    heart2_destination_rect.y = 0;
    heart2_destination_rect.w = GRID_stage2*2;
    heart2_destination_rect.h = GRID_stage2*2;

    //�Ҷ�� �ؽ��� �ε�
    SDL_Surface* conch_surface = IMG_Load("../../resources/stage2/stage2_conch.png");
    conch_texture = SDL_CreateTextureFromSurface(g_renderer, conch_surface);
    SDL_FreeSurface(conch_surface);
    conch_destination_rect.x = conch1->getX() * GRID_stage2;
    conch_destination_rect.y = conch1->getY() * GRID_stage2;
    conch_destination_rect.w = GRID_stage2;
    conch_destination_rect.h = GRID_stage2;


    f_state = -1;
    stop = true;
    for (int i = 0; i < 4; i++) {
        f_list[i] = false;
    }
    game_result = 0;
    system("cls");
}

void Stage2::HandleEvents() {
    SDL_Event event;
    if (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            g_flag_running = false;
            break;
        case SDL_KEYDOWN:

            if (event.key.keysym.sym == SDLK_ESCAPE) {
                if (stage2_status == 1) {//���� ���� ���̾����� �Ͻ�������
                    stage2_status = 2;
                }
                else if (stage2_status == 2) {//�Ͻ����������� ���� ������
                    stage2_status = 1;
                }
            }
            if (stage2_status == 2) {
                break;
            }

            if (event.key.keysym.sym == SDLK_LEFT) {
                f_state = 0;
                f_list[f_state] = true;
                stop = false;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT) {
                f_state = 1;
                f_list[f_state] = true;
                stop = false;
            }
            else if (event.key.keysym.sym == SDLK_UP) {
                f_state = 2;
                f_list[f_state] = true;
                stop = false;
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
                f_state = 3;
                f_list[f_state] = true;
                stop = false;
            }
            break;
        case SDL_KEYUP:
            if (event.key.keysym.sym == SDLK_LEFT) {
                f_list[0] = false;
            }
            else if (event.key.keysym.sym == SDLK_RIGHT) {
                f_list[1] = false;
            }
            else if (event.key.keysym.sym == SDLK_UP) {
                f_list[2] = false;
            }
            else if (event.key.keysym.sym == SDLK_DOWN) {
                f_list[3] = false;
            }

            if (f_list[0])
                f_state = 0;
            if (f_list[1])
                f_state = 1;
            if (f_list[2])
                f_state = 2;
            if (f_list[3])
                f_state = 3;
            if (f_list[0] != true && f_list[1] != true && f_list[2] != true && f_list[3] != true)
                stop = true;

            break;
        }
    }
}

void Stage2::Update() {

    conch1->move(0, 0);
    conch2->move(0, 0);

    if (turtle->isInvincible()) {
        int timer = turtle->getInvincibleTimer();
        timer--;
        if (timer <= 0) {
            turtle->setInvincible(false); // ���� ���� ����
            timer = 0; // Ÿ�̸� �ʱ�ȭ
        }
        turtle->setInvincibleTimer(timer);
    }
    // ���� �������� Ÿ�̸Ӹ� ���ҽ�Ŵ
    rabbitSpawnTimer--;

    // Ÿ�̸Ӱ� 0�� �Ǹ� �䳢�� �������ϰ� Ÿ�̸Ӹ� �缳����
    if (rabbitSpawnTimer <= 0) {
        rabbit->spawn(); // �䳢 ������
        rabbitSpawnTimer = RABBIT_SPAWN_TIME; // Ÿ�̸� �ʱ�ȭ
    }

    // coral2_spawn_timer�� ���ҽ�Ű��, ���� �ð��� ����ϸ� coral2�� ���¸� ����
    coral2_spawn_timer--;
    if (coral2_spawn_timer <= 0) {
        coral2_visible = !coral2_visible; // coral2�� ���¸� �����Ͽ� ��Ÿ���ų� ��������� ����
        coral2_spawn_timer = CORAL2_SPAWN_TIME; // Ÿ�̸� �缳��
    }

    if (!stop) {
        int x = turtle->getX();
        int y = turtle->getY();

        if (f_list[0]) {
            x -= 1;
            f_list[0] = false;
        }
        else if (f_list[1]) {
            x += 1;
            f_list[1] = false;
        }
        else if (f_list[2]) {
            y -= 1;
            f_list[2] = false;
        }
        else if (f_list[3]) {
            y += 1;
            f_list[3] = false;
        }

        if (x >= SCREEN_WIDTH) x = SCREEN_WIDTH - 1;
        if (x < 0) x = 0;
        if (y >= SCREEN_HEIGHT) y = SCREEN_HEIGHT - 1;
        if (y < 0) y = 0;

        // �ź��̰� ��ȣ�� ���� �ʴ� ��쿡�� �̵�
        if (x >= 0 && x < SCREEN_WIDTH && y >= 0 && y < SCREEN_HEIGHT && !Maze::isCoral(x, y)) {
            turtle->move(x, y); // �̵� ������ ��쿡�� �̵� �޼��� ȣ��
        }
    }
    // �ź����� ���� ���� ������Ʈ
    if (turtle->isInvincible()) {
        // ���� �ð� ����
        turtle->setInvincibleTimer(turtle->getInvincibleTimer() - 1);
        // ���� �ð��� ������ ���� ���� ����
        if (turtle->getInvincibleTimer() <= 0) {
            turtle->setInvincible(false);
        }
    }
    


    // ��� ��ȣ���� �浹 Ȯ��
    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (Maze::maze[i][j] == 2 && turtle->getX() == j && turtle->getY() == i && coral2_visible) {
                turtle->GetAttackted(1); // �ź��̰� ��ȣ�� �浹�� �� ü�� ����
            }
        }
    }
 
    //�Ҷ�Կ� �浹Ȯ�� 
    if (turtle->isCollision_Conch(conch1)) {
        turtle->GetAttackted(1);
	}

    

    // �䳢���� �浹 Ȯ��
    if (turtle->isCollision_Rabbit(rabbit)) {
        rabbit->setCount(rabbit->getCount() + 1);
        rabbit->spawn();
    }

    //��������
    if (rabbit->getCount() == 5) {
        game_result = 1;
        g_current_game_phase = PHASE_ENDING;
    }
    if (turtle->getHealth() <= 0) {
        game_result = 2;
        g_current_game_phase = PHASE_ENDING;
    }

    
}

void Stage2::Render() {

    //����� �׸���
    SDL_RenderCopy(g_renderer, stage2_bgbgbg_texture, NULL, &stage2_bgbgbg_destination_rect);

    //��� �׸���
    SDL_RenderCopy(g_renderer, stage2_bg_texture, &stage2_bg_source_rect, &stage2_bg_destination_rect);


    COORD cur;
    cur.X = 0;
    cur.Y = 0;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);

    for (int i = 0; i < SCREEN_HEIGHT; i++) {
        for (int j = 0; j < SCREEN_WIDTH; j++) {
            if (Maze::maze[i][j] == 0) {
                cout << " ";
            }
            else if (Maze::maze[i][j] == 1) {
                coral_destination_rect.x = j * GRID_stage2+ TILE_SIZE;
                coral_destination_rect.y = i * GRID_stage2+ TILE_SIZE;
                SDL_RenderCopy(g_renderer, coral_texture, NULL, &coral_destination_rect);
                cout << " ";
            }
            else if (Maze::maze[i][j] == 2) {
                // coral2 ������
                if (coral2_visible) {
                    coral2_destination_rect.x = j * GRID_stage2+ TILE_SIZE;
                    coral2_destination_rect.y = i * GRID_stage2+ TILE_SIZE;
                    SDL_RenderCopy(g_renderer, coral2_texture, NULL, &coral2_destination_rect);
                   
                }
                
            }
        }
        cout << endl;
    }


    //�䳢���� �� �׸���
    for (int i = 0; i < rabbit->getCount(); i++) {
		gan_destination_rect.x = GRID_stage2*21 +i * GRID_stage2*2+ TILE_SIZE;
		gan_destination_rect.y = GRID_stage2*2+ TILE_SIZE*2;
		SDL_RenderCopy(g_renderer, gan_texture, NULL, &gan_destination_rect);
	}
    
      


    //ĳ���ͱ׸���
    // �䳢
    if (rabbit->getX() != turtle->getX() || rabbit->getY() != turtle->getY()) {
        rabbit_destination_rect.x = rabbit->getX() * GRID_stage2+ TILE_SIZE;
        rabbit_destination_rect.y = rabbit->getY() * GRID_stage2+ TILE_SIZE;
        SDL_RenderCopy(g_renderer, rabbit_texture, NULL, &rabbit_destination_rect);
    }

    //�ź��� �׸���
    
    if (!turtle->isInvincible() || (turtle->isInvincible() && (SDL_GetTicks() / 50) % 2 == 0)) {
        // ���� ���°� �ƴϰų�, ���� ���������� 0.5�ʸ��� ���ڰŸ����� ��
        turtle_destination_rect.x = turtle->getX() * GRID_stage2+ TILE_SIZE;
        turtle_destination_rect.y = turtle->getY() * GRID_stage2+ TILE_SIZE;
        SDL_RenderCopy(g_renderer, turtle_texture, NULL, &turtle_destination_rect);
    }
    
    //�ź��� ü�� �׸��� 
    for (int i = 0; i < turtle->getHealth(); i++) {
        heart2_destination_rect.x = GRID_stage2 * 21 + i * GRID_stage2*2+ TILE_SIZE;
        heart2_destination_rect.y = TILE_SIZE*2;
        SDL_RenderCopy(g_renderer, heart2_texture, NULL, &heart2_destination_rect);
    }

    //�Ҷ��1 �׸���
    conch_destination_rect.x = conch1->getX() * GRID_stage2+ TILE_SIZE;
    conch_destination_rect.y = conch1->getY() * GRID_stage2+ TILE_SIZE;
    SDL_RenderCopy(g_renderer, conch_texture, NULL, &conch_destination_rect);
    //�Ҷ��2 �׸���
    conch_destination_rect.x = conch2->getX() * GRID_stage2+ TILE_SIZE;
    conch_destination_rect.y = conch2->getY() * GRID_stage2+ TILE_SIZE;
    SDL_RenderCopy(g_renderer, conch_texture, NULL, &conch_destination_rect);


   

    //���� ��� ��� 
    cur.X = SCREEN_WIDTH + 10;
    cur.Y = 5;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cur);
    if (game_result == 1) {
        cout << "---�¸�---";
        cout.flush();
    }
    else if (game_result == 2) {
        cout << "---�й�---";
        cout.flush(); 
    }

    cout.flush();

    SDL_RenderPresent(g_renderer);

}
void Stage2::Reset() {//����۽� ����
    //��ü �ʱ�ȭ
    delete turtle;
    delete rabbit;
    delete coral;
    delete coral2;
    delete conch1;
    delete conch2;

    turtle = new Turtle(1, 1, 0, 3, 0);
    rabbit = new Rabbit(1, 1, 1, 3);
    coral = new Coral(0, 0, 0, 0, 1);
    coral2 = new Coral2(0, 0, 0, 0, 1);
    conch1 = new Conch(15, 15, 0, 0, 1, 0, 0);
    conch2 = new Conch(10, 10, 0, 0, 1, 0, 0);
    
    //��Ÿ


}


Stage2::~Stage2() {

    SDL_DestroyTexture(stage2_bg_texture);
    SDL_DestroyTexture(stage2_bgbgbg_texture);
    SDL_DestroyTexture(turtle_texture);
    SDL_DestroyTexture(rabbit_texture);
    SDL_DestroyTexture(coral_texture);
    SDL_DestroyTexture(coral2_texture);
    SDL_DestroyTexture(gan_texture);
    SDL_DestroyTexture(heart0_texture);
    SDL_DestroyTexture(heart2_texture);
    SDL_DestroyTexture(conch_texture);

    delete turtle;
    delete rabbit;
    delete coral;


}