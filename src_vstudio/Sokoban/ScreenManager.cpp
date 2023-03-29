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

    screen_state = menu;
}

void ScreenManager::update( sf::Time elapsed_time )
{
    switch (screen_state)
    {
        case menu:
            menuScreen.update(&game_window);
            if (menuScreen.let_s_play())
            {
                game.load_lvl(menuScreen.get_lvl_selected());
                screen_state = play;
            }
            break;
        case play:
            game.update(elapsed_time);
            break;
        case score:
            break;
        default:
            break;
    }
}

void ScreenManager::draw()
{
    switch (screen_state)
    {
        case menu:
            menuScreen.draw(&game_window);
            break;
        case play:
            game.draw(&game_window);
            break;
        case score:
            break;
        default:
            break;
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
