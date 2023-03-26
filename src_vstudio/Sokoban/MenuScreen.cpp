#include "MenuScreen.h"

void MenuScreen::init()
{
	if (!texture_tileset_menu.loadFromFile( "sprites/tileset_menu.png" ))
		load_sprite_error = true;


	float x = 0, y = 0;
	for (int rect = 0; rect < 50; rect++)
	{

		if (rect == 9 || rect == 19 || rect == 29 || rect == 39 || rect == 49)
		{
			x = 0;
			y = y + TILE_LVL_W;
		}

		tab_sprite_lvl_sel[rect].setTexture( texture_tileset_menu );
		tab_sprite_lvl_sel[rect].setTextureRect( sf::IntRect( x, y, TILE_LVL_W, TILE_LVL_W ) );
		x = x + TILE_LVL_W;
	}

	x = 0, y = 0;
	for (int rect = 0; rect < 50; rect++)
	{

		if (rect == 9 || rect == 19 || rect == 29 || rect == 39 || rect == 49)
		{
			x = 0;
			y = y + TILE_LVL_W;
		}

		tab_sprite_lvl_sel_over[rect].setTexture( texture_tileset_menu );
		tab_sprite_lvl_sel_over[rect].setTextureRect( sf::IntRect( x, y, TILE_LVL_W, TILE_LVL_W ) );
		
		x = x + TILE_LVL_W;
	}

}

void MenuScreen::update()
{
}

void MenuScreen::draw(sf::RenderWindow *game_window)
{
	game_window->clear();
	/*
	float x = 0.f, y = 0.f;

	for (int spr = 0; spr < 50; spr++)
	{

		x = x + (TILE_LVL_W * Config::GLOBAL_SCALE);
		y = 0;

		if (spr == 10)
		{
			x = 0;
			y = y + (TILE_LVL_W * Config::GLOBAL_SCALE);
		}

		tab_sprite_lvl_sel[spr].setPosition( x, y );
		tab_sprite_lvl_sel[spr].setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );

		game_window->draw( tab_sprite_lvl_sel[spr] );
	}
	*/
	tab_sprite_lvl_sel[15].setPosition( 0, 0 );
	tab_sprite_lvl_sel[15].setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );

	game_window->display();
}
