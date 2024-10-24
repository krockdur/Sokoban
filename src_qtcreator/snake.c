#include "snake.h"
#include "map.h"

int tab_snake[MAX_SNAKE_LENGTH][2] = { 0 };
int snake_length = 6;

void init_snake()
{
    int head_start_x = 15;
    int head_start_y = 20;
    set_snake_head_position(head_start_x, head_start_y);
    for (int i = 1; i < snake_length; i++)
    {
        tab_snake[i][0] = head_start_x + i;
        tab_snake[i][1] = head_start_y;
    }
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
        tab_new_snake[0][1] = tab_snake[0][1];
        break;

    case RIGHT:
        tab_new_snake[0][0] = tab_snake[0][0] + 1;
        tab_new_snake[0][1] = tab_snake[0][1];
        break;

    case DOWN:
        tab_new_snake[0][0] = tab_snake[0][0];
        tab_new_snake[0][1] = tab_snake[0][1] + 1;
        break;

    case UP:
        tab_new_snake[0][0] = tab_snake[0][0];
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

