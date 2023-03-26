#ifndef MENU_SCREEN
#define MENU_SCREEN

#include <SFML/Graphics.hpp>

#include "Config.h"

class MenuScreen
{
public:
	MenuScreen() = default;
	void init();
	void update();
	void draw( sf::RenderWindow *game_window );
private:
	const float TILE_LVL_W = 32.f;

	sf::Texture texture_tileset_menu;

	sf::Sprite tab_sprite_lvl_sel[50];
	sf::Sprite tab_sprite_lvl_sel_over[50];

	bool load_sprite_error{ false };
};

#endif // !MENU_SCREEN



