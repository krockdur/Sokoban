#include "Game.h"

Game::Game() {

}

void Game::init() {
	

	bool load_sprite_error = false;

	player = Player("Krock");
	map = Map();

	// load textures

	if (!texture_box.loadFromFile("sprites/sprite_caisse.png"))
		load_sprite_error = true;
	if (!texture_background.loadFromFile("sprites/sprite_bg.png"))
		load_sprite_error = true;
	if (!texture_obj.loadFromFile("sprites/sprite_obj.png"))
		load_sprite_error = true;
	if (!texture_player.loadFromFile("sprites/sprite_player.png"))
		load_sprite_error = true;
	if (!texture_player_on_obj.loadFromFile( "sprites/sprite_player_on_obj.png" ))
		load_sprite_error = true;
	if (!texture_wall.loadFromFile("sprites/sprite_wall.png"))
		load_sprite_error = true;

	// init sprites
	sprite_box.setTexture(texture_box);
	sprite_bg.setTexture(texture_background);
	sprite_obj.setTexture(texture_obj);
	sprite_player.setTexture(texture_player);
	sprite_wall.setTexture(texture_wall);

	// create window
	game_window.create(sf::VideoMode(800, 600), "Sokoban");
}



void Game::loop() {

	while (game_window.isOpen())
	{

		sf::Time elapsed_time = Clock.getElapsedTime();
	
		while (game_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				game_window.close();

			this->update();
		}
		
		this->draw();

	}

}

void Game::update()
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


			// -- GAUCHE
		case left:

			// -- OBTENIR CASE L1 & L2
			Case case_l1 = map.get_case(map.get_case_player().get_x() - 1, map.get_case_player().get_y());
			Case case_l2 = map.get_case(map.get_case_player().get_x() - 2, map.get_case_player().get_y());

			// -- STATUS CASE L1
			switch (context.l1)
			{

			case Config::c_empty_tile:
				map.set_case_player(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
				moved = true;
				break;

			case Config::c_wall_tile:
				break;

			case Config::c_box_tile:

				// -- STATUS L2
				switch (context.l2)
				{

					// -- CASE L2: VIDE
				case Config::c_empty_tile:
					// bouger la box
					// On vide L1 et on remplie L2
					Case new_case_l1 = Case(case_l1.get_x(), case_l1.get_y(), Config::c_empty_tile);
					Case new_case_l2 = Case(case_l2.get_x(), case_l2.get_y(), Config::c_box_tile);;

					map.change_case_value(new_case_l1);
					map.change_case_value(new_case_l2);

					map.set_case_player(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
					moved = true;
					break;

				case Config::c_objective_tile:

					new_case_l1 = Case(case_l1.get_x(), case_l1.get_y(), Config::c_empty_tile);
					map.change_case_value(new_case_l1);
					map.set_case_player(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;

			case Config::c_objective_tile:
				// Player on objective case
				map.set_case_player( Case( case_l1.get_x(), case_l1.get_y(), Config::c_player_tile ) );
				moved = true;
				break;
			}

			break;

		case right:

			// -- OBTENIR CASE L1 & L2
			Case case_r1 = map.get_case(map.get_case_player().get_x() + 1, map.get_case_player().get_y());
			Case case_r2 = map.get_case(map.get_case_player().get_x() + 2, map.get_case_player().get_y());

			// -- STATUS CASE L1
			switch (context.r1)
			{

			case Config::c_empty_tile:
				map.set_case_player(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
				moved = true;
				break;

			case Config::c_wall_tile:
				break;

			case Config::c_box_tile:

				// -- STATUS L2
				switch (context.r2)
				{

					// -- CASE L2: VIDE
				case Config::c_empty_tile:
					// bouger la box
					// On vide L1 et on remplie L2
					Case new_case_r1 = Case(case_r1.get_x(), case_r1.get_y(), Config::c_empty_tile);
					Case new_case_r2 = Case(case_r2.get_x(), case_r2.get_y(), Config::c_box_tile);;

					map.change_case_value(new_case_r1);
					map.change_case_value(new_case_r2);

					map.set_case_player(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
					moved = true;
					break;

				case Config::c_objective_tile:

					new_case_r1 = Case(case_r1.get_x(), case_r1.get_y(), Config::c_empty_tile);
					map.change_case_value(new_case_r1);
					map.set_case_player(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;

			case Config::c_objective_tile:
				// Player on objective case
				map.set_case_player( Case( case_r1.get_x(), case_r1.get_y(), Config::c_player_tile ) );
				moved = true;
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

				// -- STATUS T2
				switch (context.t2)
				{

					// -- CASE T2: VIDE
				case Config::c_empty_tile:
					// bouger la box
					// On vide L1 et on remplie L2
					Case new_case_t1 = Case(case_t1.get_x(), case_t1.get_y(), Config::c_empty_tile);
					Case new_case_t2 = Case(case_t2.get_x(), case_t2.get_y(), Config::c_box_tile);;

					map.change_case_value(new_case_t1);
					map.change_case_value(new_case_t2);

					map.set_case_player(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
					moved = true;
					break;

				case Config::c_objective_tile:

					new_case_t1 = Case(case_t1.get_x(), case_t1.get_y(), Config::c_empty_tile);
					map.change_case_value(new_case_t1);
					map.set_case_player(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;

			case Config::c_objective_tile:
				// Player on objective case
				map.set_case_player( Case( case_t1.get_x(), case_t1.get_y(), Config::c_player_tile ) );
				moved = true;
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

				// -- STATUS B2
				switch (context.b2)
				{

					// -- CASE B2: VIDE
				case Config::c_empty_tile:
					// bouger la box
					// On vide B1 et on remplie B2
					Case new_case_b1 = Case(case_b1.get_x(), case_b1.get_y(), Config::c_empty_tile);
					Case new_case_b2 = Case(case_b2.get_x(), case_b2.get_y(), Config::c_box_tile);;

					map.change_case_value(new_case_b1);
					map.change_case_value(new_case_b2);

					map.set_case_player(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
					moved = true;
					break;

				case Config::c_objective_tile:

					new_case_b1 = Case(case_b1.get_x(), case_b1.get_y(), Config::c_empty_tile);
					map.change_case_value(new_case_b1);
					map.set_case_player(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;

			case Config::c_objective_tile:
				// Player on objective case
				map.set_case_player( Case( case_b1.get_x(), case_b1.get_y(), Config::c_player_tile ) );
				moved = true;
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

/*
#ifdef WINDOWS
	system("cls");
#endif
#ifdef LINUX 
	//system("clear");
#endif
*/
	for (int y = 0; y < NB_TILE_Y; y++)
	{
		for (int x = 0; x < NB_TILE_X; x++)
		{
			float coord_x = x * TILE_W;
			float coord_y = y * TILE_W;
			
			if (map.get_case(x, y).get_value() == Config::c_box_tile)
			{
				sf::Sprite tmp_sprite_box(texture_box);
				tmp_sprite_box.setPosition(coord_x, coord_y);
				game_window.draw(tmp_sprite_box);
			}
			
			if (map.get_case(x, y).get_value() == Config::c_empty_tile)
			{
				sf::Sprite tmp_sprite_bg(texture_background);
				tmp_sprite_bg.setPosition(coord_x, coord_y);
				game_window.draw(tmp_sprite_bg);
			}
			
			if (map.get_case(x, y).get_value() == Config::c_objective_tile)
			{
				sf::Sprite tmp_sprite_obj(texture_obj);
				tmp_sprite_obj.setPosition(coord_x, coord_y);
				game_window.draw(tmp_sprite_obj);
			}

			if (map.get_case(x, y).get_value() == Config::c_player_tile)
			{
				sf::Sprite tmp_sprite_player(texture_player);
				tmp_sprite_player.setPosition(coord_x, coord_y);
				game_window.draw(tmp_sprite_player);
			}

			if (map.get_case( x, y ).get_value() == Config::c_player_on_objective_tile)
			{
				sf::Sprite tmp_sprite_player_on_obj( texture_player_on_obj );
				tmp_sprite_player_on_obj.setPosition( coord_x, coord_y );
				game_window.draw( tmp_sprite_player_on_obj );
			}

			if (map.get_case(x, y).get_value() == Config::c_wall_tile)
			{
				sf::Sprite tmp_sprite_wall(texture_wall);
				tmp_sprite_wall.setPosition(coord_x, coord_y);
				game_window.draw(tmp_sprite_wall);
			}
			
		}
	}


	game_window.display();
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

