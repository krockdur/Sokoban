#include "snake.h"

int tab_snake[SNAKE_LENGTH][2] = { 0 };


void init_snake()
{
    set_snake_head_position(15, 20);
}

void set_snake_head_position( int x, int y )
{
    tab_snake[0][0] = x;
    tab_snake[0][1] = y;
}
