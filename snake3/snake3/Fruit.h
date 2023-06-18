#pragma once

#include <cstdlib>

class Fruit
{
public:
    Fruit(int width, int height);

    void GenerateNewFruit(int width, int height);

    int GetX() const;
    int GetY() const;
    
    void Movef();
    
    int state;

private:
    int x;
    int y;
};
