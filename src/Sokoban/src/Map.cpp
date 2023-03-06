/*
 * Map.cpp
 *
 *  Created on: 6 mars 2023
 *      Author: a430885
 */

#include "Map.h"


std::array<std::array<int, 16>, 16> Map::tab_map;
int Map::points_count;
bool Map::win;

Map::Map() {
	// TODO Auto-generated constructor stub

}

Map::~Map() {
	// TODO Auto-generated destructor stub
}



void Map::check_if_win()
{
	Map::win = true;
	// suppression du player actuel

	for (auto i = 0; i < NB_TILE_Y; i++)
	{
		for (auto j = 0; j < NB_TILE_X; j++)
		{
			if (Map::tab_map[i][j] == 3)
			{
				Map::win = false;
				break;
			}
		}
	}
}

void Map::load_lvl(int lvl)
{
	/*
		0 -> vide
		1 -> mur collision
		2 -> player
		3 -> objet � bouger
		4 -> objectif
		5 -> objets auxiliaires � d�placer
	*/
	Map::tab_map =
	{
		{
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 5, 0, 0, 3, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1 },
			{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
			{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
		}
	};

	Map::points_count = 0;
	Map::win = false;

}

void Map::print_map(bool debug)
{
	int color = 0;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleTextAttribute(hConsole, 7);
	for (auto i = 0; i < NB_TILE_Y; i++)
	{
		std::cout << "| ";
		for (auto j = 0; j < NB_TILE_Y; j++)
		{
			// Couleur du player
			if (Map::tab_map[i][j] == 2)
				SetConsoleTextAttribute(hConsole, 12 | BACKGROUND_RED);

			// Couleur des objets � pousser
			if (Map::tab_map[i][j] == 3)
				SetConsoleTextAttribute(hConsole, 10 | BACKGROUND_GREEN);

			// Couleur des m�rs
			if (Map::tab_map[i][j] == 1)
				SetConsoleTextAttribute(hConsole, 14);

			// Couleur objectif
			if (Map::tab_map[i][j] == 4)
				SetConsoleTextAttribute(hConsole, 9 | BACKGROUND_BLUE);

			// Couleur obstacle
			if (Map::tab_map[i][j] == 5)
				SetConsoleTextAttribute(hConsole, 11 | BACKGROUND_INTENSITY | BACKGROUND_INTENSITY);

			std::cout << Map::tab_map[i][j];

			SetConsoleTextAttribute(hConsole, 7);
			std::cout << " | ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;

	// Infos de debug
	if (debug)
	{
		// Recherche et affiche la position du player
		int case_player_x = 0;
		int case_player_y = 0;
		for (auto i = 0; i < NB_TILE_Y; i++)
		{
			for (auto j = 0; j < NB_TILE_X; j++)
			{
				if (Map::tab_map[i][j] == 2)
				{
					case_player_x = j;
					case_player_y = i;
				}
			}
		}

		SetConsoleTextAttribute(hConsole, 12);

		std::cout << "PLAYER X : " << case_player_x << "  | Y : " << case_player_y << " WIN : " << Map::win << std::endl;
	}

}

void Map::set_player_position(int case_x, int case_y)
{
	// suppression du player actuel
	for (auto i = 0; i < NB_TILE_Y; i++)
	{
		for (auto j = 0; j < NB_TILE_X; j++)
		{
			if (Map::tab_map[i][j] == 2)
			{
				Map::tab_map[i][j] = 0;
				break;
			}
		}
	}

	// inscription de la nouvelle position du player
	Map::tab_map[case_y][case_x] = 2;

}

int Map::get_case_value(int case_x, int case_y)
{
	return tab_map[case_y][case_x];
}

void Map::move_object(int old_case_x, int old_case_y, std::string direction)
{
	int new_case_x = old_case_x;
	int new_case_y = old_case_y;



	if (direction == "up")
	{
		new_case_y -= 1;
	}
	if (direction == "down")
	{
		new_case_y += 1;
	}
	if (direction == "left")
	{
		new_case_x -= 1;
	}
	if (direction == "right")
	{
		new_case_x += 1;
	}

	// contenu de la case rencontr�e
	int old_case_value = tab_map[old_case_y][old_case_x];

	// contenu de la prochaine case
	int new_case_value = Map::tab_map[new_case_y][new_case_x];

	// Si la nouvelle case est l'objectif et qu'on bouge un objet objectif
	if (new_case_value == 4 && old_case_value == 3)
	{
		Map::tab_map[new_case_y][new_case_x] = 4;
		Map::points_count++;
	}
	else if (old_case_value == 5)
	{
		Map::tab_map[new_case_y][new_case_x] = 5;
	}
	else if (old_case_value == 3)
	{
		Map::tab_map[new_case_y][new_case_x] = 3;
	}


}

