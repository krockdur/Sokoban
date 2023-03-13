#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Case.h"

class Player {
private:
	int x;
	int y;
	char value;
	std::string name;

public:
	Player() = default;
	Player(std::string name, int x, int y);
	~Player();

	Case get_position();
	void set_position(Case new_position);
	char get_value(){return this->value;};
};

#endif /* PLAYER_H_ */
