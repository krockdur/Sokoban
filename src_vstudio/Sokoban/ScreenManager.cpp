#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
    init();
}

void ScreenManager::init()
{
	game_window.create( sf::VideoMode( Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT ), "Sokoban 1982" );

	menuScreen.init();
}

void ScreenManager::update( )
{
	menuScreen.update(&game_window);
}

void ScreenManager::draw()
{
	menuScreen.draw( &game_window );
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

            update();
        }

        draw();
    }
}
