#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_LENGTH 150

extern int tab_snake[SNAKE_LENGTH][2];

extern void init_snake();
extern void set_snake_head_position( int, int);

#endif