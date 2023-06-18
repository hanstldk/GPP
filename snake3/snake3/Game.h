#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
#include <chrono>
#include "Snake.h"
#include "Fruit.h"

class Game
{
public:
    Game();
    void Run();

private:
    static const int WIDTH = 50;
    static const int HEIGHT = 18;

    int count = 0;

    Snake snake;
    Fruit fruit;

    bool gameOver;

    void ResetCursorPos(int,int);
    void ProcessInput();
    void Update();
    void Render();

    void StartScreen();
    void PrintGameOver();
};
