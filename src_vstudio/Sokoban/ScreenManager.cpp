#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
    init();
}

void ScreenManager::init()
{
	game_window.create( sf::VideoMode( Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT ), "Sokoban 1982" );

	menuScreen.init();
    game.init();
}

bool game_launched = false;
void ScreenManager::update( sf::Time elapsed_time )
{
    if (!game_launched)
    {
	    menuScreen.update(&game_window);
    }

    if (menuScreen.let_s_play() && !game_launched)
    {
        lvl_selected = menuScreen.get_lvl_selected();
        game.load_lvl( lvl_selected );
        game_launched = true;
    }

    if (game_launched)
    {
        game.update( elapsed_time ); 
    }
}

void ScreenManager::draw()
{
    if (!game_launched)
    {
	    menuScreen.draw( &game_window );
    }
    else
    {
        game.draw( &game_window );
    }
}

void ScreenManager::run()
{
    while (game_window.isOpen())
    {
        // Process events
        sf::Event event;
        while (game_window.pollEvent( event ))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                game_window.close();

            sf::Time elapsed_time = Clock.getElapsedTime();
            update( elapsed_time );
        }

        draw();
    }
}
