
#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <iostream>
#include <fstream>
#include "Case.h"

#include <string>

#define NB_TILE_X 16
#define NB_TILE_Y 16

class Map {
private:
	std::vector<Case> map;
	void populate_map();


public:
	Map();
	~Map();

	Case get_case(int x, int y);
	void change_case_value(Case c, int value);

	void print_map();

};

#endif /* MAP_H_ */
