#include "Game.h"


void SetColor(int backgroundColor, int textColor)
{
    int color = backgroundColor * 16 + textColor;

    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(consoleHandle, color);
}

void HideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(consoleHandle, &cursorInfo);
    cursorInfo.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &cursorInfo);
}

Game::Game() : snake(WIDTH, HEIGHT), fruit(WIDTH, HEIGHT), gameOver(false)
{
    
}

void Game::ResetCursorPos(int x,int y) {
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cursorPosition;
    cursorPosition.X = x;
    cursorPosition.Y = y;
    SetConsoleCursorPosition(consoleHandle, cursorPosition);
}

void Game::Run()
{
    gameOver = true;
    HideCursor();
    
    StartScreen();
    while (1) {
        int input = _getch();
        if (input == 49) { gameOver = false; break; }
    }
    
   
    while (!gameOver)
    {
        std::chrono::steady_clock::time_point startTime = std::chrono::steady_clock::now();

        ProcessInput();
        Update();
        Render();

        std::chrono::steady_clock::time_point currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedTime = currentTime - startTime;

        
        startTime = currentTime;

        
        double elapsedSeconds = elapsedTime.count();
        std::cout << "Elapsed Time: " << elapsedSeconds << " seconds" << std::endl;
        std::cout << "FPS : " << 1/elapsedSeconds << std::endl;

    }
    PrintGameOver();
}

void Game::ProcessInput()
{
    if (_kbhit())
    {
        char input = _getch();
        Direction dir;

        switch (input)
        {
        case 'w':
            dir = Direction::UP;
            break;
        case 's':
            dir = Direction::DOWN;
            break;
        case 'a':
            dir = Direction::LEFT;
            break;
        case 'd':
            dir = Direction::RIGHT;
            break;
        case 'q':
            gameOver = true;
            return;
        default:
            return;
        }

        snake.ChangeDirection(dir);
    }
}

void Game::Update()
{
    count++;
    if (snake.CollisionWithFruit(fruit.GetX(), fruit.GetY()))
    {
        fruit.GenerateNewFruit(WIDTH, HEIGHT);
    }

    if (fruit.GetX() > WIDTH || fruit.GetX() < 1)
    {
        fruit.GenerateNewFruit(WIDTH, HEIGHT);
    }


    if (fruit.GetY() > HEIGHT || fruit.GetY() < 1)
    {
        fruit.GenerateNewFruit(WIDTH, HEIGHT);
    }

    snake.Move();
    if (count == 2)
    {
        fruit.Movef(); count = 0;
    }

    if (snake.CollisionWithSelf() || snake.CollisionWithWall(WIDTH, HEIGHT))
    {
        gameOver = true;
    }
}

void Game::Render()
{
    ResetCursorPos(0,0);

    for (int i = 0; i <= WIDTH + 1; i++)
    {
        SetColor(8, 13);
        std::cout << "=";
    }
    std::cout << std::endl;

    for (int y = 1; y <= HEIGHT; y++)
    {
        for (int x = 0; x <= WIDTH + 1; x++)
        {
            if (x == 0 || x == WIDTH + 1)
            {
                SetColor(8, 13);
                std::cout << "|";
            }
            else if (x == fruit.GetX() && y == fruit.GetY())
            {
                SetColor(4, 12);
                std::cout << "D";
            }
            else if (x == snake.GetHeadX() && y == snake.GetHeadY())
            {
                SetColor(13, 9);
                std::cout << snake.CheckDirection();
            }
            else if (snake.IsTailPosition(x, y))
            {
                SetColor(10, 9);
                std::cout << "8";
            }
            else
            {
                SetColor(15, 13);
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for (int i = 0; i <= WIDTH + 1; i++)
    {
        SetColor(8, 13);
        std::cout << "=";
    }
    std::cout << std::endl;
    std::cout << "²¿¸®°¹¼ö :" << snake.score << std::endl;
}

void Game::StartScreen() 
{
    ResetCursorPos(0, 0);
    std::cout << "******************************************" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*              Áö··ÀÌ °ÔÀÓ               *" << std::endl;
    std::cout << "*             (Snake  Bite)              *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*             1. °ÔÀÓ ½ÃÀÛ               *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "*                                        *" << std::endl;
    std::cout << "******************************************" << std::endl;
}

void Game::PrintGameOver() 
{
    ResetCursorPos(0, 0);
    SetColor(1, 12);
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    std::cout << "    #####       ###      #           #  ########      ######    #           #  ########  #######       \n";
    std::cout << "   ##   ##     #  ##     ##         ##  #            #      #    #         #   #         #      #      \n";
    std::cout << "  ##           #   #     # #       # #  #           #        #    #       #    #         #       #     \n";
    std::cout << "  #     ###   ######     #  #     #  #  ########    #        #     #     #     ########  ########      \n";
    std::cout << "  ##     #    #    #     #   #   #   #  #           #       ##      #   #      #         #    #        \n";
    std::cout << "   ##  ##    #      #    #    # #    #  #            #     ##        # #       #         #     #       \n";
    std::cout << "    ####    #        #   #     #     #  ########      #####           #        ########  #      ##     \n";
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    std::cout << "                                                                                                            \n";
    while (true) {
    }
}

