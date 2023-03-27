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
	float offset_tilset_over = 5 * 32;
	for (int rect = 0; rect < 50; rect++)
	{
		tab_sprite_lvl_sel_over[rect].setTexture(texture_tileset_menu);
		tab_sprite_lvl_sel_over[rect].setTextureRect(sf::IntRect(x, y + offset_tilset_over, TILE_LVL_W, TILE_LVL_W));

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

}

void MenuScreen::update(sf::RenderWindow* game_window)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);

	int mouse_num_line = 0;			// sur quelle case de la grille se trouve la souris
	int mouse_num_col = 0;

	mouse_over_lvl_sel = false;

	for (int line = 0; line < 5; line++)
	{
		if (mouse_position.y > line * Config::TILE_W * Config::GLOBAL_SCALE && mouse_position.y < (line * Config::TILE_W * Config::GLOBAL_SCALE) + Config::TILE_W * Config::GLOBAL_SCALE)
		{
			for (int col = 0; col < 10; col++)
			{
				if (mouse_position.x > col * Config::TILE_W * Config::GLOBAL_SCALE && mouse_position.x < (col * Config::TILE_W * Config::GLOBAL_SCALE) + Config::TILE_W * Config::GLOBAL_SCALE)
				{
					mouse_num_col = col;
					mouse_num_line = line;
					mouse_over_lvl_sel = true;
					break;
				}
			}
			
		}

	}

	// calcul de la case sur laquelle se trouve la souris
	mouse_case_over = mouse_num_line * 10 + mouse_num_col;

	std::cout << "------------------------------" << std::endl;
	std::cout << "mouse over : " << mouse_case_over << std::endl;
	std::cout << "mouse on col :  " << mouse_num_col << std::endl;

}

void MenuScreen::draw(sf::RenderWindow *game_window)
{
	game_window->clear();
	
	float x = 0.f, y = 0.f;

	for (int spr = 0; spr < 50; spr++)
	{

		tab_sprite_lvl_sel[spr].setPosition( x, y );
		tab_sprite_lvl_sel[spr].setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );
		tab_sprite_lvl_sel_over[spr].setPosition(x, y);
		tab_sprite_lvl_sel_over[spr].setScale(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE);

		if (spr == mouse_case_over && mouse_over_lvl_sel)
			game_window->draw(tab_sprite_lvl_sel_over[spr]);
		else
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
