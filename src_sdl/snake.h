#ifndef SNAKE_H
#define SNAKE_H

#define SNAKE_LENGTH 150

// variables
extern int tab_snake[SNAKE_LENGTH][2];
extern int snake_length;


// fonctions
extern void init_snake();
extern void set_snake_head_position( int, int);
extern void set_snake_element_position( int, int, int);
extern void move_snake_left();
extern void move_sanke_right();
extern void move_sanke_top();
extern void move_sanke_down();

#endif