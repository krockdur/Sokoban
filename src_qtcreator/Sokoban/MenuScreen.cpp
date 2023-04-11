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

        tab_sprite_lvl_sel[rect].setTextureRect( sf::IntRect(sf::Vector2i(x, y), sf::Vector2i(Config::TILE_MENU_W, Config::TILE_MENU_W)) );
        //tab_sprite_lvl_sel[rect].setTextureRect( sf::IntRect( x, y, Config::TILE_MENU_W, Config::TILE_MENU_W ) );
		
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
        //tab_sprite_lvl_sel_over[rect].setTextureRect(sf::IntRect(x, y + offset_tilset_over, Config::TILE_MENU_W, Config::TILE_MENU_W));
        tab_sprite_lvl_sel_over[rect].setTextureRect(sf::IntRect(sf::Vector2i(x, y + offset_tilset_over), sf::Vector2i(Config::TILE_MENU_W, Config::TILE_MENU_W)));


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
    sprite_title.setTextureRect( sf::IntRect( sf::Vector2i(0, 320), sf::Vector2i(Config::TEXTURE_MENU_TITLE_W, Config::TEXTURE_MENU_TITLE_H)) );

	// sprite btn play
    sprite_btn_play.setTexture( texture_tileset_menu );
    sprite_btn_play.setTextureRect( sf::IntRect( sf::Vector2i(0, 352), sf::Vector2i(Config::TEXTURE_MENU_BTN_PLAY_W, Config::TEXTURE_MENU_BTN_PLAY_H) ) );

	// sprite btn score
    sprite_btn_score.setTexture( texture_tileset_menu );
    sprite_btn_score.setTextureRect(sf::IntRect(sf::Vector2i(0, 384), sf::Vector2i(Config::TEXTURE_MENU_BTN_SCORE_W, Config::TEXTURE_MENU_BTN_SCORE_H)));


}

void MenuScreen::update(sf::RenderWindow* game_window)
{

	sf::Vector2i mouse_position = sf::Mouse::getPosition(*game_window);

	int mouse_num_line = 0;			// sur quelle case de la grille se trouve la souris
	int mouse_num_col = 0;

	mouse_over_lvl_sel = false;
/*
	for (int line = 0; line < 5; line++)
	{
        if (mouse_position.y > offset_grid_lvl_y + line * Config::TILE_MENU_W * Config::GLOBAL_SCALE && mouse_position.y < offset_grid_lvl_y + (line * Config::TILE_MENU_W * Config::GLOBAL_SCALE) + Config::TILE_MENU_W * Config::GLOBAL_SCALE)
		{
			for (int col = 0; col < 10; col++)
			{
                if (mouse_position.x > offset_grid_lvl_x + col * Config::TILE_MENU_W * Config::GLOBAL_SCALE && mouse_position.x < offset_grid_lvl_x + (col * Config::TILE_MENU_W * Config::GLOBAL_SCALE) + Config::TILE_MENU_W * Config::GLOBAL_SCALE)
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
*/
    // Choices lvl button

    int i = 0, j = 0;
    for (int btn = 0; btn <= 49; btn++)
    {
        float tmp_x_btn = 0, tmp_y_btn = 0;

        tmp_x_btn = i * Config::TILE_MENU_W * Config::GLOBAL_SCALE + i * Config::SPACE_BETWEEN_TILE_MENU;
        tmp_y_btn = j * Config::TILE_MENU_W * Config::GLOBAL_SCALE + j * Config::SPACE_BETWEEN_TILE_MENU;

        sf::FloatRect tmp_r_lvl_button(
            sf::Vector2f(offset_grid_lvl_x + tmp_x_btn, offset_grid_lvl_y + tmp_y_btn),
            sf::Vector2f(Config::TILE_MENU_W * Config::GLOBAL_SCALE, Config::TILE_MENU_W * Config::GLOBAL_SCALE)
            );

        i = i + 1;
        if (i == 10)
        {
            i = 0;
            j = j + 1;
        }

        if (tmp_r_lvl_button.contains(sf::Vector2f((float)mouse_position.x, (float)mouse_position.y)))
        {
            mouse_case_over = btn;
            lvl_selected = btn + 1;
        }
    }


    // play button
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
        sf::FloatRect r_play_button(
            sf::Vector2f(sf::Vector2f((((Config::WINDOW_WIDTH / 2) * Config::SCREEN_RATIO)) - (Config::TEXTURE_MENU_BTN_PLAY_W * Config::GLOBAL_SCALE /2), 653.f) ),
            sf::Vector2f(128.f * Config::GLOBAL_SCALE, 32.f * Config::GLOBAL_SCALE)
		);

        if (r_play_button.contains(sf::Vector2f((float)mouse_position.x, (float)mouse_position.y)) && !btn_play_pressed)
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
	


    // Titre
    sprite_title.setScale( sf::Vector2f(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE));
    sprite_title.setPosition(
        sf::Vector2f(
            (Config::CURRENT_WINDOW_WIDTH / 2) - Config::TEXTURE_MENU_TITLE_W * Config::GLOBAL_SCALE / 2,
            12
            )
        );
    game_window->draw(sprite_title);


	// grille des niveaux

    offset_grid_lvl_x = (Config::CURRENT_WINDOW_WIDTH / 2) - (Config::TILE_MENU_W * 10 + Config::SPACE_BETWEEN_TILE_MENU * 9) * Config::GLOBAL_SCALE / 2;
    float x = 0.f, y = 0.f;
    int i = 0, j = 0;
    for (int spr = 0; spr <= 49; spr++)
	{
        x = i * Config::TILE_MENU_W * Config::GLOBAL_SCALE + i * Config::SPACE_BETWEEN_TILE_MENU;
        y = j * Config::TILE_MENU_W * Config::GLOBAL_SCALE + j * Config::SPACE_BETWEEN_TILE_MENU;


        tab_sprite_lvl_sel[spr].setPosition( sf::Vector2f(offset_grid_lvl_x + x, offset_grid_lvl_y + y) );

        tab_sprite_lvl_sel[spr].setScale( sf::Vector2f(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE));

        tab_sprite_lvl_sel_over[spr].setPosition(sf::Vector2f(offset_grid_lvl_x + x, offset_grid_lvl_y + y));

        tab_sprite_lvl_sel_over[spr].setScale(sf::Vector2f(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE));

        if (spr == mouse_case_over && mouse_over_lvl_sel)
            game_window->draw(tab_sprite_lvl_sel_over[spr]);
        else
            game_window->draw( tab_sprite_lvl_sel[spr] );


        i = i + 1;
        if (i == 10)
        {
            i = 0;
            j = j + 1;
        }


	}

    // boutton play
    sprite_btn_play.setPosition( sf::Vector2f((((Config::WINDOW_WIDTH / 2) * Config::SCREEN_RATIO)) - (Config::TEXTURE_MENU_BTN_PLAY_W * Config::GLOBAL_SCALE /2), 653.f) );
    sprite_btn_play.setScale( sf::Vector2f(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE ));
	game_window->draw( sprite_btn_play );

    // boutton score
    sprite_btn_score.setPosition(sf::Vector2f((((Config::WINDOW_WIDTH / 2) * Config::SCREEN_RATIO)) - (Config::TEXTURE_MENU_BTN_SCORE_W * Config::GLOBAL_SCALE /2), 750.f));
    sprite_btn_score.setScale(sf::Vector2f(Config::GLOBAL_SCALE, Config::GLOBAL_SCALE));
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
