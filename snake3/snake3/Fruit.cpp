#include "Fruit.h"

Fruit::Fruit(int width, int height)
{
    GenerateNewFruit(width, height);
}

void Fruit::GenerateNewFruit(int width, int height)
{
    x = 0;
    y = 0;
    state = rand() % 4;
    switch (state)
    {
        case 0:
            x=1 + rand() % (width - 2);
            y = height - 1;
            break;
        case 1:
            x = 1 + rand() % (width - 2);
            y = 1;
            break;
        case 2:
            x = 1;
            y = 1 + rand() % (height - 2);
            break;
        case 3:
            x = width - 1;
            y = 1 + rand() % (height - 2);
            break;
    }
    //x = 1 + rand() % (width - 2);
    //y = 1 + rand() % (height - 2); 
}

int Fruit::GetX() const
{
    return x;
}

int Fruit::GetY() const
{
    return y;
}

void Fruit::Movef()
{
    switch (state)
    {
    case 0:
        y--;
        break;
    case 1:
        y++;
        break;
    case 2:
        x++;
        break;
    case 3:
        x--;
        break;
    }
}