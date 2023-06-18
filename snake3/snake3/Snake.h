#pragma once

#include <vector>

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Position
{
    int x;
    int y;
};

class Snake
{
public:
    Snake(int width, int height);

    void Move();
    void ChangeDirection(Direction dir);
    char CheckDirection();
    bool CollisionWithSelf() const;
    bool CollisionWithWall(int width, int height) const;
    bool CollisionWithFruit(int fruitX, int fruitY);

    int GetHeadX() const;
    int GetHeadY() const;
    bool IsTailPosition(int x, int y) const;

    int score = 0;

private:
    std::vector<Position> body;
    Direction direction;
};