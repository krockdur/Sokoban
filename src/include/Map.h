#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <iostream>
#include <fstream>
#include "Case.h"

#include <string>
#include <filesystem>

#include <typeinfo>

#define NB_TILE_X 16
#define NB_TILE_Y 16

class Map {
private:
	std::vector<Case> map;
	void populate_map();
	void set_player_position(Case player_position);

public:
	Map() = default;
	Map(Case case_player);
	~Map();

	Case get_case(int x, int y);
	void change_case_value(Case new_case);

	void print_map();

};

#endif /* MAP_H_ */
