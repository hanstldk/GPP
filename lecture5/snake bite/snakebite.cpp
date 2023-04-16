//#define DEBUG
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <string>

using namespace std;

const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
int tailX[200], tailY[200];
int nTail;
enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirection dir;
bool gameOver;
int ranklist[10];

char buffer[height][width];
char screen[height][width];

void gotoxy(int x, int y) {
    //x, y ��ǥ ����
    COORD pos = { x,y };
    //Ŀ�� �̵�
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ranking() {
    
}

void print_ranking() {
    for (int i = 0;i < 10;i++) {
        std::cout << to_string(i + 1) + "��" + " : " + to_string(ranklist[i])<<endl;
    }
   
}

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = rand() % width;
    fruitY = rand() % height;
    score = 0;
    nTail = 0;
    tailX[100] = {};
    tailY[100] = {};
}

void Draw() {
    system("cls");

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        cout << "o";
                        print = true;
                    }
                }
                if (!print)
                    cout << " ";
            }
            if (j == width - 1)
                cout << "#";
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;

    cout << "Score:" << score << endl; //������ ����մϴ�.
    cout << "Length:" << nTail << endl; //���� ���̸� ����մϴ�.
}

void Input() {
    if (_kbhit()) {
        switch (_getch()) {
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    //���� ���� �ε������� üũ�մϴ�.
    if (x > width || x < 0 || y > height || y < 0)
        gameOver = true;

    //���� �Ӹ��� ����� �ε������� üũ�մϴ�.
    for (int i = 0; i < nTail; i++) {
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    }

    //���� ������ �Ծ����� üũ�մϴ�.
    if (x == fruitX && y == fruitY) {
        score += 10;
        fruitX = rand() % width;
        fruitY = rand() % height;
        nTail++;
    }
    if (gameOver) {
        cout << "Game Over" << endl;
        cout << "Score: " << score << endl;
    }
}


// game_state == 0 �϶�
int print_title_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              ������ ����               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;

#ifdef DEBUG
    std::cout << "*            - ����� ��� -             *" << std::endl;
#else
    std::cout << "*                                        *" << std::endl;
#endif  
    std::cout << "*   1. ���� ����                         *" << std::endl;
    std::cout << "*   2. ���� ����                         *" << std::endl;
    std::cout << "*   3. ���� ��ŷ ����                    *" << std::endl;
    std::cout << "*   4. ���� ���� (esc)                   *" << std::endl;
    std::cout << "******************************************" << std::endl;

    return 0;
}


// game_state == 2 �϶�
int print_introduction_screen()
{
    std::cout << "******************************************" << std::endl;
    std::cout << "Ÿ��Ʋȭ������ ���ư����? (Y/N)" << std::endl;
    return 0;
}

int main()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = false; // Ŀ���� ������ �ʵ��� ����
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);

    int game_state = 0;
    int is_game_running = 1;

    while (is_game_running)
    {
        char key_input = '0';
        switch (game_state)
        {
        case 0:
            print_title_screen();
            key_input = _getch();
            switch (key_input)
            {
            case '1':
                game_state = 1;
                break;
            case '2':
                game_state = 2;
                break;
            case '3':
                game_state = 3;
                break;
            case '4':
                is_game_running = 0;
                break;
            case 27:
                is_game_running = 0;
                break;
            default:
                break;
            }
            break;
        case 1:
            Setup();
            while (!gameOver) {
                Draw();
                Input();
                Logic();
                Sleep(10); //���� �ӵ��� �����մϴ�.
            }
            ranking();
            game_state = 0;
            break;
        case 2:
            print_introduction_screen();
            key_input = _getch();
            switch (key_input)
            {
            case 'y':
                game_state = 0;
                break;
            case 'n':
                break;
            default:
                break;
            }
            break;
        case 3:
            print_ranking();
            key_input = _getch();
            switch (key_input)
            {
            case 1:
                game_state = 0;
                break;
            case 2:
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }


    }

    return 0;
}