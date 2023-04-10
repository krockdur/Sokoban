#ifndef SCREEN_MANAGER
#define SCREEN_MANAGER

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "MenuScreen.h"
#include "Game.h"

class ScreenManager
{
private:
	sf::RenderWindow game_window;

	MenuScreen menuScreen;
	Game game;

	int lvl_selected = 0;

	sf::Clock Clock;

	enum ScreenState { menu, play, score };
	ScreenState screen_state;

public:
	ScreenManager();
	void init();
	void update( sf::Time elapsed_time );
	void draw();
	void run();
};

#endif

