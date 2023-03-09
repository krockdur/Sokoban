#ifndef PLAYER_H_
#define PLAYER_H_

#include <string>
#include "Case.h"

class Player {
private:
	int x;
	int y;
	std::string name;

public:
	Player() = default;
	Player(std::string name, int x, int y);
	~Player();

	Case get_position();
};

#endif /* PLAYER_H_ */
