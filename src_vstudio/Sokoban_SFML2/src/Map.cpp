#include "Map.h" 

Map::Map( int lvl )
{
	populate_map( lvl );

	//print_map();
}

Map::~Map()
{

}



void Map::populate_map( int lvl )
{

	//std::cout << "Current working directory: " << std::filesystem::current_path() << std::endl;

	//std::ifstream sFile("D:\\A1_DEV\\Sokoban\\src\\Sokoban\\Debug\\lvl1.txt", std::ifstream::in);
	std::ifstream sFile( "./lvls/lvl_" + std::to_string( lvl ) + ".txt", std::ifstream::in );

	if (sFile)
	{

		std::string ligne;

		int max_car_in_x = 0;
		int max_car_in_y = 0;
		int y = 0;
		while (getline( sFile, ligne ))
		{

			size_t nb_car = ligne.length();

			if (max_car_in_x < nb_car)
				max_car_in_x = nb_car;

			for (int x = 0; x < nb_car; x++)
			{
				Case c( x, y, ligne[x] );
				this->map.push_back( c );

				if (ligne[x] == Config::c_player_tile)
					case_player = c;
			}



			y++;
		}
		max_car_in_y = y;
		Config::NB_TILE_X = max_car_in_x;
		Config::NB_TILE_Y = max_car_in_y;
	}
	else
	{
		std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
	}
}

Case Map::get_case( int x, int y )
{
	Case cRet( 0, 0, ' ' );
	for (Case c : this->map)
	{
		if (c.get_x() == x && c.get_y() == y)
		{
			cRet = c;
		}
	}
	return cRet;
}

void Map::print_map()
{

	for (int y = 0; y < Config::NB_TILE_Y; y++)
	{
		std::cout << "|  ";
		for (int x = 0; x < Config::NB_TILE_X; x++)
		{
			std::cout << this->get_case( x, y ).get_value() << "  |  ";
		}
		std::cout << std::endl;
	}
}

void Map::set_map( std::vector<Case> t_map )
{
	map = t_map;
}

bool Map::check_if_win()
{
	bool win = true;
	for (Case c : map)
	{
		if (c.get_value() == Config::c_objective_tile)
			win = false;
	}

	return win;
}

void Map::set_case_player( Case cp )
{
	for (Case& c : map)
	{

		// delete old player position
		// Player on empty case
		if (c.get_value() == Config::c_player_tile)
		{
			c.set_value( Config::c_empty_tile );
		}

		// Player on objective case
		if (c.get_value() == Config::c_player_on_objective_tile)
		{
			c.set_value( Config::c_objective_tile );
		}

		// new position of the player in map
		// update position player
		if (c.get_x() == cp.get_x() && c.get_y() == cp.get_y())
		{
			if (c.get_value() == Config::c_empty_tile)
			{
				c.set_value( Config::c_player_tile );
			}
			else if (c.get_value() == Config::c_objective_tile)
			{
				c.set_value( Config::c_player_on_objective_tile );
			}
			case_player = c;
		}
	}
}


Context Map::get_case_context( Case c )
{
	int center_case_x = c.get_x();
	int center_case_y = c.get_y();

	// l1 l2
	int case_l1_x = center_case_x - 1;
	int case_l1_y = center_case_y;

	int case_l2_x = center_case_x - 2;
	int case_l2_y = center_case_y;

	// r1 r2
	int case_r1_x = center_case_x + 1;
	int case_r1_y = center_case_y;

	int case_r2_x = center_case_x + 2;
	int case_r2_y = center_case_y;

	// b1 b2
	int case_b1_x = center_case_x;
	int case_b1_y = center_case_y + 1;

	int case_b2_x = center_case_x;
	int case_b2_y = center_case_y + 2;

	// t1 t2
	int case_t1_x = center_case_x;
	int case_t1_y = center_case_y - 1;

	int case_t2_x = center_case_x;
	int case_t2_y = center_case_y - 2;

	char l1 = get_case( case_l1_x, case_l1_y ).get_value();
	char l2 = get_case( case_l2_x, case_l2_y ).get_value();

	char r1 = get_case( case_r1_x, case_r1_y ).get_value();
	char r2 = get_case( case_r2_x, case_r2_y ).get_value();

	char t1 = get_case( case_t1_x, case_t1_y ).get_value();
	char t2 = get_case( case_t2_x, case_t2_y ).get_value();

	char b1 = get_case( case_b1_x, case_b1_y ).get_value();
	char b2 = get_case( case_b2_x, case_b2_y ).get_value();

	return Context( l1, l2, r1, r2, t1, t2, b1, b2 );
}

Case Map::get_case_player()
{
	Case c_to_ret;
	for (Case c : map)
	{
		if (c.get_value() == Config::c_player_tile || c.get_value() == Config::c_player_on_objective_tile)
		{
			c_to_ret = c;
			break;
		}
	}
	return c_to_ret;
}



void Map::change_case_value( Case new_case )
{

	bool element_removed = false;

	int i = 0;

	int deleted_index = 0;

	int new_case_x = new_case.get_x();
	int new_case_y = new_case.get_y();


	for (Case c : map)
	{

		int tmp_c_x = c.get_x();
		int tmp_c_y = c.get_y();



		if (tmp_c_x == new_case_x && tmp_c_y == new_case_y)
		{

			map.erase( map.begin() + i );
			element_removed = true;
			deleted_index = i;
			break;
		}
		i++;
	}

	if (element_removed)
	{
		//map.push_back(new_case);
		map.insert( map.begin() + deleted_index, new_case );
	}


}


