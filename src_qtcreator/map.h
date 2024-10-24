#ifndef MAP_H
#define MAP_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 500
#define SCREEN_HEIGHT 500
#define NB_TILE_ALONG_X 50
#define NB_TILE_ALONG_Y 50
#define TILE_WIDTH 10
#define FPS 60
#define TIME_BETWEEN_SNAKE_MOVE 60
#define TILE_WORLD_TYPE 0
#define TILE_WALL_TYPE 1
#define TILE_APPLE_TYPE 2
#define TILE_SNAKE_TYPE 3
 

// The world limits
extern const int NB_CASE_X;
extern const int NB_CASE_Y;

// Colors of game
typedef struct { char r; char g; char b; char a; } color;
extern color color_wall;
extern color color_world;
extern color color_apple;
extern color color_snake;

// The map
extern int tab_map[NB_TILE_ALONG_Y][NB_TILE_ALONG_X];

// The functions
extern void clean_snake_from_map();
extern void include_snake_in_map();
extern void draw_map( SDL_Renderer* );


#endif
