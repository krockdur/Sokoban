#include "snake.h"

int tab_snake[150][2];

void init_snake()
{
    for (int i = 0; i < 150; i++)
    {
        tab_snake[i][0] = 0;
        tab_snake[i][1] = 0;
    }
}