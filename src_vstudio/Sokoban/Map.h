#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include <iostream>
#include <fstream>

#include "Case.h"
#include "Player.h"
#include "Context.h"
#include "Config.h"


#include <string>
#include <filesystem>

#include <typeinfo>


class Map {
private:
	std::vector<Case> map;
	void populate_map(int lvl);

	Case case_player;



public:
	Map() = default;
	Map(int lvl);
	~Map();

	Case get_case(int x, int y);
	void change_case_value(Case new_case);
	Context get_case_context(Case c);

	Case get_case_player(){ return case_player; };
	void set_case_player( Case cp );

	void print_map();


};

#endif /* MAP_H_ */
