#include "snake.h"

int tab_snake[MAX_SNAKE_LENGTH][2] = { 0 };
int snake_length = 4;

void init_snake()
{
    set_snake_head_position(15, 20);
}

void set_snake_head_position( int x, int y )
{
    tab_snake[0][0] = x;
    tab_snake[0][1] = y;
}


void move_snake(int dir)
{
    int tab_new_snake[MAX_SNAKE_LENGTH][2] = { 0 };

    switch (dir)
    {
    case LEFT:
        tab_new_snake[0][0] = tab_snake[0][0] - 1;
        break;

    case RIGHT:
        tab_new_snake[0][0] = tab_snake[0][0] + 1;
        break;

    case DOWN:
        tab_new_snake[0][1] = tab_snake[0][1] + 1;
        break;

    case UP:
        tab_new_snake[0][1] = tab_snake[0][1] - 1;
        break;

    default:
        break;
    }

    // body
    for (int i = 0; i < snake_length - 1; i++)
    {
        tab_new_snake[i + 1][0] = tab_snake[i][0];
        tab_new_snake[i + 1][1] = tab_snake[i][1];
    }

    // maj de tab_snake
    for (int i = 0; i < snake_length; i++)
    {
        tab_snake[i][0] = tab_new_snake[i][0];
        tab_snake[i][1] = tab_new_snake[i][1];
    }
}

