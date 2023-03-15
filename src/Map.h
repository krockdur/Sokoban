#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <iostream>
#include <fstream>

#include "Case.h"
#include "Player.h"
#include "Context.h"


#include <string>
#include <filesystem>

#include <typeinfo>

#define NB_TILE_X 16
#define NB_TILE_Y 16


class Map {
private:
	std::vector<Case> map;
	void populate_map();

public:
	Map() = default;
	Map(Player player);
	~Map();

	Case get_case(int x, int y);
	void change_case_value(Case new_case);
	void update_player_pos_in_map(Player player);
    Context get_case_context(Case c);


	void print_map();


};

#endif /* MAP_H_ */
