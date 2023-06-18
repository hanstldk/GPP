#include "Snake.h"
#include <cstdlib>

Snake::Snake(int width, int height)
{
    int startX = width / 2;
    int startY = height / 2;

    body.push_back({ startX, startY });
    direction = Direction::RIGHT;
}

void Snake::Move()
{
    int headX = body[0].x;
    int headY = body[0].y;

    switch (direction)
    {
    case Direction::UP:
        headY--;
        break;
    case Direction::DOWN:
        headY++;
        break;
    case Direction::LEFT:
        headX--;
        break;
    case Direction::RIGHT:
        headX++;
        break;
    }


    body.insert(body.begin(), { headX, headY });

  
    body.pop_back();
}

void Snake::ChangeDirection(Direction dir)
{
   
    if ((direction == Direction::UP && dir != Direction::DOWN) ||
        (direction == Direction::DOWN && dir != Direction::UP) ||
        (direction == Direction::LEFT && dir != Direction::RIGHT) ||
        (direction == Direction::RIGHT && dir != Direction::LEFT))
    {
        direction = dir;
    }
}

char Snake::CheckDirection()
{
    if (this->direction == Direction::UP) return 30;
    else if (this->direction == Direction::DOWN) return 31;
    else if (this->direction == Direction::RIGHT) return '>';
    else if (this->direction == Direction::LEFT) return '<';
}


bool Snake::CollisionWithSelf() const
{
    int headX = body[0].x;
    int headY = body[0].y;

    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i].x == headX && body[i].y == headY)
        {
            return true;
        }
    }

    return false;
}

bool Snake::CollisionWithWall(int width, int height) const
{
    int headX = body[0].x;
    int headY = body[0].y;

    if (headX == 0 || headX == width + 1 || headY == 0 || headY == height + 1)
    {
        return true;
    }

    return false;
}

bool Snake::CollisionWithFruit(int fruitX, int fruitY)
{
    int headX = body[0].x;
    int headY = body[0].y;

    if (headX == fruitX && headY == fruitY)
    {
        body.push_back(body[body.size() - 1]);
        score++;
        return true;
    }

    return false;
}

int Snake::GetHeadX() const
{
    return body[0].x;
}

int Snake::GetHeadY() const
{
    return body[0].y;
}

bool Snake::IsTailPosition(int x, int y) const
{
    int headX = body[0].x;
    int headY = body[0].y;

    for (size_t i = 1; i < body.size(); i++)
    {
        if (body[i].x == x && body[i].y == y)
        {
            return true;
        }
    }

    return false;
}