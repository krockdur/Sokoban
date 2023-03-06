
#ifndef MAP_H_
#define MAP_H_

#include <vector>
#include "Case.h"

class Map {
private:
	std::vector<Case> map;
	void populate_map();


public:
	Map();
	~Map();

	Case get_case(int x, int y);
	void change_case_value(Case c, int value);

};

#endif /* MAP_H_ */
