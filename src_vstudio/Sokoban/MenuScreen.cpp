#include "MenuScreen.h"

void MenuScreen::init()
{
	if (!texture_tileset_menu.loadFromFile( "sprites/tileset_menu.png" ))
		load_sprite_error = true;


	float x = 0, y = 0;
	for (int rect = 0; rect < 50; rect++)
	{
		tab_sprite_lvl_sel[rect].setTexture( texture_tileset_menu );
		tab_sprite_lvl_sel[rect].setTextureRect( sf::IntRect( x, y, TILE_LVL_W, TILE_LVL_W ) );
		
		if (rect == 9 || rect == 19 || rect == 29 || rect == 39 || rect == 49)
		{
			x = 0;
			y = y + TILE_LVL_W;
		}
		else
		{
			x = x + TILE_LVL_W;
		}
		
	}

	x = 0, y = 0;
	for (int rect = 0; rect < 50; rect++)
	{

		tab_sprite_lvl_sel_over[rect].setTexture( texture_tileset_menu );
		tab_sprite_lvl_sel_over[rect].setTextureRect( sf::IntRect( x, y, TILE_LVL_W, TILE_LVL_W ) );
		
		if (rect == 9 || rect == 19 || rect == 29 || rect == 39)
		{
			x = 0;
			y = y + TILE_LVL_W;
		}
		else
		{
			x = x + TILE_LVL_W;
		}

	}

}

void MenuScreen::update(sf::RenderWindow* game_window)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);
	std::cout << "mouse x : " << mouse_position.x << "  mouse y : " << mouse_position.y << std::endl;

	bool tab_over_menu[50];

	// ligne 0
	for (int line = 0; line < 5; line++)
	{
		if (mouse_position.y > 0 && mouse_position.y < TILE_LVL_W * Config::GLOBAL_SCALE)
		{

		}
	}


}

void MenuScreen::draw(sf::RenderWindow *game_window)
{
	game_window->clear();
	
	float x = 0.f, y = 0.f;

	for (int spr = 0; spr < 50; spr++)
	{

		tab_sprite_lvl_sel[spr].setPosition( x, y );
		tab_sprite_lvl_sel[spr].setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );

		game_window->draw( tab_sprite_lvl_sel[spr] );

		x += TILE_LVL_W * Config::GLOBAL_SCALE;

		if (spr == 9 || spr == 19 || spr == 29 || spr == 39 )
		{
			x = 0;
			y += TILE_LVL_W * Config::GLOBAL_SCALE;
		}
	}

	game_window->display();
}
