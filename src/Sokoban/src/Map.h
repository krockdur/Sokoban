/*
 * Map.h
 *
 *  Created on: 6 mars 2023
 *      Author: a430885
 */

#ifndef MAP_H_
#define MAP_H_

#include <iostream>
#include <array>
#include <windows.h>

#define NB_TILE_X 16
#define NB_TILE_Y 16

class Map {

private:
	static std::array<std::array<int, 16>, 16> tab_map;


	static int points_count;
	static bool win;

public:
	Map();
	virtual ~Map();
	static void check_if_win();
	static void load_lvl(int lvl);
	static void print_map(bool debug);
	static void set_player_position(int case_x, int case_y);
	static int get_case_value(int case_x, int case_y);
	static void move_object(int old_case_x, int old_case_y, std::string direction);

};

#endif /* MAP_H_ */
