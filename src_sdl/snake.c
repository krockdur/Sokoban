#include "snake.h"

int tab_snake[SNAKE_LENGTH][2] = { 0 };
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

void set_snake_element_position( int e, int x, int y )
{
    tab_snake[e][0] = x;
    tab_snake[e][1] = y;
}

void move_snake_left()
{
    int new_tab_snake[SNAKE_LENGTH][2] = { 0 };

    for (int i = 0; i < snake_length; i++)
    {
        new_tab_snake[i][0] = tab_snake[i+1][0];
        new_tab_snake[i][1] = tab_snake[i+1][1];
    }
}

void move_sanke_right()
{

}

void move_sanke_top()
{

}

void move_sanke_down()
{

}