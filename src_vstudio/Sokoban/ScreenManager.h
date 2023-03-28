#ifndef SCREEN_MANAGER
#define SCREEN_MANAGER

#include <SFML/Graphics.hpp>

#include "Config.h"
#include "MenuScreen.h"

class ScreenManager
{
private:
	sf::RenderWindow game_window;

	MenuScreen menuScreen;

	int lvl_selected = 0;

public:
	ScreenManager();
	void init();
	void update();
	void draw();
	void run();
};

#endif

