#include "MenuScreen.h"

void MenuScreen::init()
{
	if (!texture_tileset_menu.loadFromFile( "sprites/tileset_menu_screen.png" ))
		load_sprite_error = true;



	// sprites lvl
	int x = 0, y = 0;
	for (int rect = 0; rect < 50; rect++)
	{
		tab_sprite_lvl_sel[rect].setTexture( texture_tileset_menu );
		tab_sprite_lvl_sel[rect].setTextureRect( sf::IntRect( x, y, Config::TILE_MENU_W, Config::TILE_MENU_W ) );
		
		if (rect == 9 || rect == 19 || rect == 29 || rect == 39 || rect == 49)
		{
			x = 0;
			y = y + Config::TILE_MENU_W;
		}
		else
		{
			x = x + Config::TILE_MENU_W;
		}
		
	}

	// sprite lvl over
	x = 0, y = 0;
	int offset_tilset_over = 5 * 32;
	for (int rect = 0; rect < 50; rect++)
	{
		tab_sprite_lvl_sel_over[rect].setTexture(texture_tileset_menu);
		tab_sprite_lvl_sel_over[rect].setTextureRect(sf::IntRect(x, y + offset_tilset_over, Config::TILE_MENU_W, Config::TILE_MENU_W));

		if (rect == 9 || rect == 19 || rect == 29 || rect == 39 || rect == 49)
		{
			x = 0;
			y = y + Config::TILE_MENU_W;
		}
		else
		{
			x = x + Config::TILE_MENU_W;
		}

	}

	// sprite title
	sprite_title.setTexture( texture_tileset_menu );
	sprite_title.setTextureRect( sf::IntRect( 0, 320, 384, 32) );

	// sprite btn play
	sprite_btn_play.setTexture( texture_tileset_menu );
	sprite_btn_play.setTextureRect( sf::IntRect( 0, 352, 128, 32 ) );

	// sprite btn score
	sprite_btn_score.setTexture( texture_tileset_menu );
	sprite_btn_score.setTextureRect(sf::IntRect(0, 384, 160, 32));


}

void MenuScreen::update(sf::RenderWindow* game_window)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);

	int mouse_num_line = 0;			// sur quelle case de la grille se trouve la souris
	int mouse_num_col = 0;

	mouse_over_lvl_sel = false;

	for (int line = 0; line < 5; line++)
	{
		if (mouse_position.y > offset_grid_lvl_y + line * Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE && mouse_position.y < offset_grid_lvl_y + (line * Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE) + Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE)
		{
			for (int col = 0; col < 10; col++)
			{
				if (mouse_position.x > offset_grid_lvl_x + col * Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE && mouse_position.x < offset_grid_lvl_x + (col * Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE) + Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE)
				{
					mouse_num_col = col;
					mouse_num_line = line;
					mouse_over_lvl_sel = true;

					// calcul de la case sur laquelle se trouve la souris
					mouse_case_over = mouse_num_line * 10 + mouse_num_col;

					if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
					{
						// 
						lvl_selected = mouse_case_over + 1;
						std::cout << "lvl_selected : " << lvl_selected << std::endl;
					}

					break;
				}
			}
			
		}

	}

	// boutton play
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		sf::FloatRect r_play_button(
			576.f,
			653.f,
			128.f * Config::GLOBAL_SCALE * Config::MENU_BTN_PLAY_SCALE,
			32.f * Config::GLOBAL_SCALE * Config::MENU_BTN_PLAY_SCALE
		);

		if (r_play_button.contains((float)mouse_position.x, (float)mouse_position.y) && !btn_play_pressed)
		{
			if (lvl_selected != 0)
			{
				btn_play_pressed = true;
				std::cout << "click play lvl " << lvl_selected << std::endl;
			}
		}
	}

	if (!sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		btn_play_pressed = false;
	}
}

void MenuScreen::draw(sf::RenderWindow *game_window)
{
	game_window->clear();
	
	float x = 0.f, y = 0.f;

	// Titre
	sprite_title.setScale( Config::GLOBAL_SCALE * Config::MENU_TITLE_SCALE, Config::GLOBAL_SCALE * Config::MENU_TITLE_SCALE);
	sprite_title.setPosition( 256.f, 18.f );
	game_window->draw(sprite_title);

	// grille des niveaux

	for (int spr = 0; spr < 50; spr++)
	{

		tab_sprite_lvl_sel[spr].setPosition( offset_grid_lvl_x + x, offset_grid_lvl_y + y );
		tab_sprite_lvl_sel[spr].setScale( Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE, Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE );
		tab_sprite_lvl_sel_over[spr].setPosition(offset_grid_lvl_x + x, offset_grid_lvl_y + y);
		tab_sprite_lvl_sel_over[spr].setScale(Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE, Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE);

		//std::cout << "souris sur la case : " << mouse_case_over << std::endl;

		if (spr == mouse_case_over && mouse_over_lvl_sel)
			game_window->draw(tab_sprite_lvl_sel_over[spr]);
		else
			game_window->draw( tab_sprite_lvl_sel[spr] );

		x += Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE;

		if (spr == 9 || spr == 19 || spr == 29 || spr == 39 )
		{
			x = 0;
			y += Config::TILE_MENU_W * Config::GLOBAL_SCALE * Config::MENU_LVL_GRID_SCALE;
		}
	}

	// boutton play
	sprite_btn_play.setPosition( 576.f, 653.f );
	sprite_btn_play.setScale( Config::GLOBAL_SCALE * Config::MENU_BTN_PLAY_SCALE, Config::GLOBAL_SCALE * Config::MENU_BTN_PLAY_SCALE);
	game_window->draw( sprite_btn_play );

	// boutton score
	sprite_btn_score.setPosition(558.f, 700.f);
	sprite_btn_score.setScale(Config::GLOBAL_SCALE * Config::MENU_BTN_SCORE_SCALE, Config::GLOBAL_SCALE * Config::MENU_BTN_SCORE_SCALE);
	game_window->draw(sprite_btn_score);

	/*
	draw_debug_rect(
		game_window,
		sf::Vector2f( offset_x + 5 * Config::TILE_MENU_W * Config::GLOBAL_SCALE, offset_y + 6 * Config::TILE_MENU_W * Config::GLOBAL_SCALE ),
		sf::Vector2f(Config::GLOBAL_SCALE * Config::TILE_MENU_W,	Config::GLOBAL_SCALE * Config::TILE_MENU_W),
		sf::Color::Red
		);
	*/

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
