#ifndef SNAKE_H
#define SNAKE_H

#define MAX_SNAKE_LENGTH 150
#define LEFT 4
#define RIGHT 6
#define UP 8
#define DOWN 2

// variables
extern int tab_snake[MAX_SNAKE_LENGTH][2];
extern int snake_length;


// fonctions
extern void init_snake();
extern void set_snake_head_position( int, int);
extern void move_snake( int );

#endif