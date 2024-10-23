#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "snake.h"
#include "map.h"

// gcc main.c -o prog -I C:\\libs\\SDL\\SDL2-2.26.3\\include -L C:\\libs\\SDL\\SDL2-2.26.3\\lib\\x64 -lSDL2main -lSDL2

void init_game();
void update_game();
void draw();
void clean_screen();
void render_screen();

SDL_Window* p_window = NULL;
SDL_Renderer * p_renderer = NULL;

int main(int argc, char* argv[])
{

    if(SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError() );
        return EXIT_FAILURE;
    }

    p_window = SDL_CreateWindow("Snake_SDL2", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if ( p_window == NULL)
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError() );
        SDL_Quit();
        return EXIT_FAILURE;

    }

    p_renderer = SDL_CreateRenderer(p_window, 0, SDL_RENDERER_ACCELERATED);
    if ( p_renderer == NULL )
    {
        SDL_LogError( SDL_LOG_CATEGORY_APPLICATION, "[debug] %s", SDL_GetError() );
        SDL_Quit();
        return EXIT_FAILURE;
    }

    init_game();

    SDL_Event p_event;
    bool is_open = true;
    unsigned int actual_time = 0;
    unsigned int old_time = 0;
    unsigned int delta_time = 0;
    unsigned int fps = 0;
    while ( is_open )
    {
        while ( SDL_PollEvent( &p_event ))
        {
            switch ( p_event.type )
            {
            case SDL_QUIT:
                is_open = false;
                break;
            }
        }

        actual_time = SDL_GetTicks64();
        delta_time = actual_time - old_time;

        if (delta_time > 1000 / FPS)
        {
            printf(" FPS : %d f/s \r\n", 1000 / delta_time);

            old_time = actual_time;

            update_game();
            clean_screen();
            draw();
            render_screen();
        }

    }

    SDL_DestroyRenderer( p_renderer );
    SDL_DestroyWindow( p_window );

    SDL_Quit();

    return EXIT_SUCCESS;
}

void init_game()
{
    init_snake();
}

void update_game()
{

}


SDL_Point point_A = { 0, 0 };
SDL_Point point_B = { 300, 300 };
SDL_Rect rect_test = { 150, 150, 30, 20 };
SDL_Point point_test = { 100, 25 };
void draw()
{
    for (int y = 0; y < NB_CASE_Y; y++)
    {
        for (int x = 0; x < NB_CASE_X; x++)
        {
            // wall
            if (tab_map[y][x] == 1)
            {
                SDL_Rect tmp_wall_rect = { x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH };
                SDL_SetRenderDrawColor( p_renderer, color_wall.r, color_wall.g, color_wall.b, color_wall.a );
                SDL_RenderFillRect( p_renderer, &tmp_wall_rect );
            }
            // world
            if (tab_map[y][x] == 0)
            {
                SDL_Rect tmp_world_rect = { x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH };
                SDL_SetRenderDrawColor( p_renderer, color_world.r, color_world.g, color_world.b, color_world.a );
                SDL_RenderFillRect( p_renderer, &tmp_world_rect );
            }
            // apple
            if (tab_map[y][x] == 2)
            {
                SDL_Rect tmp_apple_rect = { x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH };
                SDL_SetRenderDrawColor( p_renderer, color_apple.r, color_apple.g, color_apple.b, color_apple.a );
                SDL_RenderFillRect( p_renderer, &tmp_apple_rect );
            }
            // snake
            if (tab_map[y][x] == 3)
            {
                SDL_Rect tmp_snake_rect = { x * TILE_WIDTH, y * TILE_WIDTH, TILE_WIDTH, TILE_WIDTH };
                SDL_SetRenderDrawColor( p_renderer, color_snake.r, color_snake.g, color_snake.b, color_snake.a );
                SDL_RenderFillRect( p_renderer, &tmp_snake_rect );
            }
        }
    }

}

void clean_screen()
{
    SDL_SetRenderDrawColor( p_renderer, 0, 0, 125, 255 );
    SDL_RenderClear( p_renderer );
}

void render_screen()
{
    SDL_RenderPresent( p_renderer );
}
