#include "MenuScreen.h"

void MenuScreen::init()
{
	if (!texture_tileset_menu.loadFromFile( "sprites/tileset_menu.png" ))
		load_sprite_error = true;
	if (!texture_btn.loadFromFile( "sprites/btn.png" ))
		load_sprite_error = true;


	int x = 0, y = 0;
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
	int offset_tilset_over = 5 * 32;
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

	sprite_btn_play.setTexture( texture_btn );


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

	// boutton play
	if (sf::Mouse::isButtonPressed( sf::Mouse::Left ))
	{


		sf::FloatRect r_button( 
			offset_x + 5 * TILE_LVL_W * Config::GLOBAL_SCALE,
			offset_y + 6 * TILE_LVL_W * Config::GLOBAL_SCALE,
			Config::GLOBAL_SCALE * TILE_LVL_W,
			Config::GLOBAL_SCALE * TILE_LVL_W
			);
		
		if (r_button.contains( mouse_position.x, mouse_position.y ))
		{
			std::cout << "click play" << std::endl;
		}

		/*

		if (mouse_position.x > offset_x + 5 * TILE_LVL_W * Config::GLOBAL_SCALE && mouse_position.x < offset_x + 5 * TILE_LVL_W * Config::GLOBAL_SCALE + TILE_LVL_W)
		{
			if (mouse_position.y > offset_y + 6 * TILE_LVL_W * Config::GLOBAL_SCALE && mouse_position.y < offset_y + 6 * TILE_LVL_W * Config::GLOBAL_SCALE + TILE_LVL_W)
			{
				std::cout << "click play" << std::endl;
			}
		}
		*/
	}

}

void MenuScreen::draw(sf::RenderWindow *game_window)
{
	game_window->clear();
	
	float x = 0.f, y = 0.f;

	for (int spr = 0; spr < 50; spr++)
	{

		tab_sprite_lvl_sel[spr].setPosition( offset_x + x, offset_y + y );
		tab_sprite_lvl_sel[spr].setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );
		tab_sprite_lvl_sel_over[spr].setPosition(offset_x + x, offset_y + y);
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


	sprite_btn_play.setPosition( offset_x + 5 * TILE_LVL_W * Config::GLOBAL_SCALE, offset_y + 6 * TILE_LVL_W * Config::GLOBAL_SCALE );
	sprite_btn_play.setScale( Config::GLOBAL_SCALE, Config::GLOBAL_SCALE );
	game_window->draw( sprite_btn_play );


	draw_debug_rect(
		game_window,
		sf::Vector2f( offset_x + 5 * TILE_LVL_W * Config::GLOBAL_SCALE, offset_y + 6 * TILE_LVL_W * Config::GLOBAL_SCALE ),
		sf::Vector2f(Config::GLOBAL_SCALE * TILE_LVL_W,	Config::GLOBAL_SCALE * TILE_LVL_W),
		sf::Color::Red
		);



	game_window->display();
}

void MenuScreen::draw_debug_rect(sf::RenderWindow *game_window, sf::Vector2f pos, sf::Vector2f size, sf::Color outline_color )
{
	sf::RectangleShape r(size);
	r.setPosition( pos );
	r.setFillColor( sf::Color::Transparent );
	r.setOutlineColor( outline_color );
	r.setOutlineThickness( 2.f );
	game_window->draw( r );
}
