#ifndef MENU_SCREEN
#define MENU_SCREEN

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Config.h"

class MenuScreen
{
public:
	MenuScreen() = default;
	void init();
	void update(sf::RenderWindow* game_window);
	void draw( sf::RenderWindow *game_window );
private:
	const int TILE_LVL_W = 32;

	float offset_x = 10.f;
	float offset_y = 20.f;
	
	int mouse_case_over = 0;
	bool mouse_over_lvl_sel = false;

	sf::Texture texture_tileset_menu;
	sf::Texture texture_btn;

	sf::Sprite tab_sprite_lvl_sel[50];
	sf::Sprite tab_sprite_lvl_sel_over[50];
	sf::Sprite sprite_btn_play;

	bool load_sprite_error{ false };
};

#endif // !MENU_SCREEN



