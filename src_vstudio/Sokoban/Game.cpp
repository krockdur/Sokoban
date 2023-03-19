#include "Game.h"

Game::Game() {

}

void Game::init() {
	player = Player("Krock", 1, 1);
	map = Map(player);
}


void Game::loop() {

	while (Game::run)
	{

		sf::Time elapsed_time = Clock.getElapsedTime();


		if (elapsed_time.asMilliseconds() >= TIME_BETWEEN_FRAME)
		{

			this->update();

			this->draw();

			Clock.restart();

			std::cout << elapsed_time.asMicroseconds() << std::endl;
		}

	}

}

bool moved = false;
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
		this->run = false;
		direction = none;
	}

	Context context = map.get_case_context(player.get_position());

	if (!moved)
	{
		switch (direction)
		{


			// -- GAUCHE
		case left:

			// -- OBTENIR CASE L1 & L2
			Case case_l1 = map.get_case(player.get_position().get_x() - 1, player.get_position().get_y());
			Case case_l2 = map.get_case(player.get_position().get_x() - 2, player.get_position().get_y());

			// -- STATUS CASE L1
			switch (context.l1)
			{

			case Config::c_empty_tile:
				player.set_position(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
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

					player.set_position(Case(case_l1.get_x(), case_l1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;

			case Config::c_objective_tile:

				break;
			}

			break;

		case right:

			// -- OBTENIR CASE L1 & L2
			Case case_r1 = map.get_case(player.get_position().get_x() + 1, player.get_position().get_y());
			Case case_r2 = map.get_case(player.get_position().get_x() + 2, player.get_position().get_y());

			// -- STATUS CASE L1
			switch (context.r1)
			{

			case Config::c_empty_tile:
				player.set_position(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
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

					player.set_position(Case(case_r1.get_x(), case_r1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;
			}

			break;

		case up:

			// -- OBTENIR CASE T1 & T2
			Case case_t1 = map.get_case(player.get_position().get_x(), player.get_position().get_y() - 1);
			Case case_t2 = map.get_case(player.get_position().get_x(), player.get_position().get_y() - 2);

			// -- STATUS CASE T1
			switch (context.t1)
			{

			case Config::c_empty_tile:
				player.set_position(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
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

					player.set_position(Case(case_t1.get_x(), case_t1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;
			}

			break;

		case down:

			// -- OBTENIR CASE B1 & B2
			Case case_b1 = map.get_case(player.get_position().get_x(), player.get_position().get_y() + 1);
			Case case_b2 = map.get_case(player.get_position().get_x(), player.get_position().get_y() + 2);

			// -- STATUS CASE B1
			switch (context.b1)
			{

			case Config::c_empty_tile:
				player.set_position(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
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

					player.set_position(Case(case_b1.get_x(), case_b1.get_y(), Config::c_player_tile));
					moved = true;
					break;
				}

				break;
			}

			break;

		default:
			break;
		}
	}



	map.update_player_pos_in_map(player);

}

void Game::draw()
{
#ifdef WINDOWS
	system("cls");
#endif
#ifdef LINUX 
	//system("clear");
#endif

	map.print_map();

	debug(map.get_case_context(player.get_position()));
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

