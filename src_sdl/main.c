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

    int snake_direction = LEFT;

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
            case SDL_KEYDOWN:
                switch( p_event.key.keysym.sym )
                {
                    case SDLK_q:
                        snake_direction = LEFT;
                        break;
                    case SDLK_d:
                        snake_direction = RIGHT;
                        break;
                    case SDLK_z:
                        snake_direction = UP;
                        break;
                    case SDLK_s:
                        snake_direction = DOWN;
                        break;
                }
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
    
    // clean snake from map
    clean_snake_from_map();

    // move snake
    move_snake(snake_direction);

    // include snake in map
    for (int i = 0; i < snake_length; i++)
    {
        tab_map[tab_snake[i][1]][tab_snake[i][0]] = 3;
    }

}

void draw()
{
    draw_map( p_renderer );
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