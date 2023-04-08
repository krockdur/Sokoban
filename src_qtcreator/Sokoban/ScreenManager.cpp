#include "ScreenManager.h"


ScreenManager::ScreenManager()
{
    init();
    
}

void ScreenManager::init()
{
    //game_window.create( sf::VideoMode( sf::Vector2u(Config::WINDOW_WIDTH, Config::WINDOW_HEIGHT) ), "Sokoban 1982" );
    //game_window.create( sf::VideoMode( sf::Vector2u(2560, 1440) ), "Sokoban 1982" , sf::Style::Fullscreen );


    std::vector<sf::VideoMode> resolutions = sf::VideoMode::getFullscreenModes();

    sf::VideoMode best_resolution = sf::VideoMode::getFullscreenModes()[0];

    sf::VideoMode desktop_resolution = sf::VideoMode::getDesktopMode();

    game_window.create( desktop_resolution  , "Sokoban 1982", sf::Style::None);
    game_window.setPosition(sf::Vector2(0, 0));
    sf::Vector2u w_size = game_window.getSize();


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
            Clock.restart();
        }

        draw();
    }
}
