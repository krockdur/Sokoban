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

    //sf::VideoMode best_resolution = sf::VideoMode::getFullscreenModes()[0];

    sf::VideoMode desktop_resolution = sf::VideoMode::getDesktopMode();

    //game_window.create( desktop_resolution  , "Sokoban 1982", sf::Style::None);
    //game_window.create( desktop_resolution, "Sokoban 1982" );
    game_window.create( desktop_resolution, "Sokoban 1982", sf::Style::Fullscreen );

    game_window.setPosition( sf::Vector2( 0, 0 ) );
    game_window.setFramerateLimit( 60 );

    sf::Vector2u current_screen_size = game_window.getSize();

    Config::CURRENT_WINDOW_HEIGHT = current_screen_size.y;
    Config::CURRENT_WINDOW_WIDTH = current_screen_size.x;

    //Config::SCREEN_RATIO = current_screen_size.x / Config::WINDOW_WIDTH;
    Config::SCREEN_RATIO = current_screen_size.x / current_screen_size.y;
    Config::GLOBAL_SCALE = Config::SCREEN_RATIO;


    menuScreen.init();
    game.init();

    screen_state = menu;
}

void ScreenManager::update( sf::Time elapsed_time )
{
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::R ))
    {
        game.load_lvl( menuScreen.get_lvl_selected() );
    }
    if (sf::Keyboard::isKeyPressed( sf::Keyboard::M ))
    {
        screen_state = menu;
    }

    switch (screen_state)
    {
    case menu:
        menuScreen.update( &game_window );
        if (menuScreen.let_s_play())
        {
            game.load_lvl( menuScreen.get_lvl_selected() );
            screen_state = play;
        }
        break;
    case play:
        game.update( elapsed_time );
        if (game.check_if_win())
            screen_state = menu;
        if (!game.get_is_alive())
            screen_state = menu;
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
        menuScreen.draw( &game_window );
        break;
    case play:
        game.draw( &game_window );
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
