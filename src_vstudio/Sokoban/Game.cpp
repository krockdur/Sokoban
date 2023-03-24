#include "Game.h"

Game::Game() {

}

void Game::init() {

	player = Player("Krock");
	map = Map();

	load_textures();

	create_sprites();

	game_window.create(sf::VideoMode(1920, 1080), "Sokoban");
}



void Game::loop() {

	while (game_window.isOpen())
	{

		sf::Time elapsed_time = Clock.getElapsedTime();

		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game_window.close();

				this->update( elapsed_time );

		}

		this->draw();

	}

}

void Game::update( sf::Time elapsed_time )
{

	enum Direction { up, down, left, right, none };

	Direction direction;
	direction = none;

	// Autoriser le déplacement
	if (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z) && !sf::Keyboard::isKeyPressed(sf::Keyboard::Q) && !sf::Keyboard::isKeyPressed(sf::Keyboard::S) && !sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		moved = false;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		direction = up;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		direction = left;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		direction = down;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		direction = right;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		//this->run = false;
		game_window.close();
		direction = none;
	}

	Context context = map.get_case_context(map.get_case_player());

	if (!moved)
	{
		switch (direction)
		{

			case left:

				Case case_l1 = map.get_case(map.get_case_player().get_x() - 1, map.get_case_player().get_y());
				Case case_l2 = map.get_case(map.get_case_player().get_x() - 2, map.get_case_player().get_y());

				switch (context.l1)
				{

					case Config::c_empty_tile:
						map.set_case_player(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_box_tile:

						switch (context.l2)
						{
							case Config::c_empty_tile:
								transfert_object(case_l1, case_l2, Config::c_empty_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object(case_l1, case_l2, Config::c_empty_tile, Config::c_box_on_objective);
								break;
						}

						break;

					case Config::c_objective_tile:
						map.set_case_player(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_box_on_objective:

						switch (context.l2)
						{

							case Config::c_empty_tile:
								transfert_object(case_l1, case_l2, Config::c_objective_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object( case_l1, case_l2, Config::c_objective_tile, Config::c_box_on_objective );
								break;
						}

						break;

				}

				break;

			case right:

				Case case_r1 = map.get_case(map.get_case_player().get_x() + 1, map.get_case_player().get_y());
				Case case_r2 = map.get_case(map.get_case_player().get_x() + 2, map.get_case_player().get_y());

				switch (context.r1)
				{

					case Config::c_empty_tile:
						map.set_case_player(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_wall_tile:
						break;

					case Config::c_box_tile:

						switch (context.r2)
						{
							case Config::c_empty_tile:
								transfert_object(case_r1, case_r2, Config::c_empty_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object(case_r1, case_r2, Config::c_empty_tile, Config::c_box_on_objective);
								break;
						}

						break;

					case Config::c_objective_tile:
						map.set_case_player(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_box_on_objective:

						switch (context.r2)
						{
							case Config::c_empty_tile:
								transfert_object(case_r1, case_r2, Config::c_objective_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object( case_r1, case_r2, Config::c_objective_tile, Config::c_box_on_objective );
								break;
						}

						break;
				}

				break;

			case up:

				// -- OBTENIR CASE T1 & T2
				Case case_t1 = map.get_case(map.get_case_player().get_x(), map.get_case_player().get_y() - 1);
				Case case_t2 = map.get_case(map.get_case_player().get_x(), map.get_case_player().get_y() - 2);

				// -- STATUS CASE T1
				switch (context.t1)
				{

					case Config::c_empty_tile:
						map.set_case_player(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_wall_tile:
						break;

					case Config::c_box_tile:

						switch (context.t2)
						{
							case Config::c_empty_tile:
								transfert_object(case_t1, case_t2, Config::c_empty_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object(case_t1, case_t2, Config::c_empty_tile, Config::c_box_on_objective);
								break;
						}

						break;

					case Config::c_objective_tile:
						// Player on objective case
						map.set_case_player(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_box_on_objective:

						switch (context.t2)
						{
							case Config::c_empty_tile:
								transfert_object(case_t1, case_t2, Config::c_objective_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object( case_t1, case_t2, Config::c_objective_tile, Config::c_box_on_objective );
								break;
						}

						break;

				}

				break;

			case down:

				// -- OBTENIR CASE B1 & B2
				Case case_b1 = map.get_case(map.get_case_player().get_x(), map.get_case_player().get_y() + 1);
				Case case_b2 = map.get_case(map.get_case_player().get_x(), map.get_case_player().get_y() + 2);

				// -- STATUS CASE B1
				switch (context.b1)
				{

					case Config::c_empty_tile:
						map.set_case_player(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_wall_tile:
						break;

					case Config::c_box_tile:

						switch (context.b2)
						{
							case Config::c_empty_tile:
								transfert_object(case_b1, case_b2, Config::c_empty_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object(case_b1, case_b2, Config::c_empty_tile, Config::c_box_on_objective);
								break;
						}

						break;

					case Config::c_objective_tile:
						// Player on objective case
						map.set_case_player(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
						moved = true;
						break;

					case Config::c_box_on_objective:

						switch (context.b2)
						{
							case Config::c_empty_tile:
								transfert_object(case_b1, case_b2, Config::c_objective_tile, Config::c_box_tile);
								break;

							case Config::c_objective_tile:
								transfert_object( case_b1, case_b2, Config::c_objective_tile, Config::c_box_on_objective );
								break;
						}

						break;

				}

				break;

			default:
				break;
		}
	}

}

void Game::draw()
{

	game_window.clear();

	for (int y = 0; y < Config::NB_TILE_Y; y++)
	{
		for (int x = 0; x < Config::NB_TILE_X; x++)
		{
			float coord_x = x * Config::TILE_W * 2;
			float coord_y = y * Config::TILE_W * 2;

			if (map.get_case(x, y).get_value() == Config::c_box_tile)
			{
				sf::Sprite tmp_sprite_box(texture_box);
				tmp_sprite_box.setPosition(coord_x, coord_y);
				tmp_sprite_box.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_box);
			}

			if (map.get_case(x, y).get_value() == Config::c_empty_tile)
			{
				sf::Sprite tmp_sprite_bg(texture_background);
				tmp_sprite_bg.setPosition(coord_x, coord_y);
				tmp_sprite_bg.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_bg);
			}

			if (map.get_case(x, y).get_value() == Config::c_objective_tile)
			{
				sf::Sprite tmp_sprite_obj(texture_obj);
				tmp_sprite_obj.setPosition(coord_x, coord_y);
				tmp_sprite_obj.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_obj);
			}

			if (map.get_case(x, y).get_value() == Config::c_player_tile)
			{
				sf::Sprite tmp_sprite_player(texture_player);
				tmp_sprite_player.setPosition(coord_x, coord_y);
				tmp_sprite_player.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_player);
			}

			if (map.get_case(x, y).get_value() == Config::c_player_on_objective_tile)
			{
				sf::Sprite tmp_sprite_player_on_obj(texture_player_on_obj);
				tmp_sprite_player_on_obj.setPosition(coord_x, coord_y);
				tmp_sprite_player_on_obj.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_player_on_obj);
			}

			if (map.get_case(x, y).get_value() == Config::c_wall_tile)
			{
				sf::Sprite tmp_sprite_wall(texture_wall);
				tmp_sprite_wall.setPosition(coord_x, coord_y);
				tmp_sprite_wall.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_wall);
			}

			if (map.get_case(x, y).get_value() == Config::c_box_on_objective)
			{
				sf::Sprite tmp_sprite_box_on_obj(texture_box_on_obj);
				tmp_sprite_box_on_obj.setPosition(coord_x, coord_y);
				tmp_sprite_box_on_obj.setScale( 2.0f, 2.0f );
				game_window.draw(tmp_sprite_box_on_obj);
			}

		}
	}


	game_window.display();
}


/*
Description du contexte
---------------------------------------------
|	  	|	  	|	  T2	|	  	|	  	|
---------------------------------------------
|	  	|	  	|	  T1	|	  	|	  	|
---------------------------------------------
|	L2	|	L1	|	PLAYER	|	R1	|	R2	|
---------------------------------------------
|	  	|	  	|	  B1	|	  	|	  	|
---------------------------------------------
|	  	|	  	|	  B2	|	  	|	  	|
---------------------------------------------

start_case	= B1 ou T1 ou L1 ou R1
next_case	= B2 ou T2 ou L2 ou R2

*/
void Game::transfert_object(Case start_case, Case next_case, char new_value_start_case, char new_value_next_case)
{
	Case new_case_1 = Case(start_case.get_x(), start_case.get_y(), new_value_start_case);
	Case new_case_2 = Case(next_case.get_x(), next_case.get_y(), new_value_next_case);;

	map.change_case_value(new_case_1);
	map.change_case_value(new_case_2);

	// Déplacement du player sur start_case
	map.set_case_player(Case(start_case.get_x(), start_case.get_y(), Config::c_player_tile));
	moved = true;
}

void Game::load_textures()
{
	if (!texture_box.loadFromFile( "sprites/sprite_caisse.png" ))
		load_sprite_error = true;
	if (!texture_box_on_obj.loadFromFile( "sprites/sprite_caisse_on_obj.png" ))
		load_sprite_error = true;
	if (!texture_background.loadFromFile( "sprites/sprite_bg.png" ))
		load_sprite_error = true;
	if (!texture_obj.loadFromFile( "sprites/sprite_obj.png" ))
		load_sprite_error = true;
	if (!texture_player.loadFromFile( "sprites/sprite_player.png" ))
		load_sprite_error = true;
	if (!texture_player_on_obj.loadFromFile( "sprites/sprite_player_on_obj.png" ))
		load_sprite_error = true;
	if (!texture_wall.loadFromFile( "sprites/sprite_wall.png" ))
		load_sprite_error = true;
}

void Game::create_sprites()
{
	sprite_box.setTexture( texture_box );
	sprite_bg.setTexture( texture_background );
	sprite_obj.setTexture( texture_obj );
	sprite_player.setTexture( texture_player );
	sprite_wall.setTexture( texture_wall );
}

void Game::debug(Context c)
{

	char A = c.t2;
	char B = c.t1;
	char C = c.l2;
	char D = c.l1;
	char E = c.r1;
	char F = c.r2;
	char G = c.b1;
	char H = c.b2;


	std::cout << "XXXXXXXXXXX|  " << A << "  |XXXXXXXXXXXX" << std::endl;
	std::cout << "-----------|-----|------------" << std::endl;
	std::cout << "XXXXXXXXXXX|  " << B << "  |XXXXXXXXXXXX" << std::endl;
	std::cout << "-----------|-----|------------" << std::endl;
	std::cout << "  " << C << "  |  " << D << "  |  @  |  " << E << "  |  " << F << "  |" << std::endl;
	std::cout << "-----------|-----|------------" << std::endl;
	std::cout << "XXXXXXXXXXX|  " << G << "  |XXXXXXXXXXXX" << std::endl;
	std::cout << "-----------|-----|------------" << std::endl;
	std::cout << "XXXXXXXXXXX|  " << H << "  |XXXXXXXXXXXX" << std::endl;
}

