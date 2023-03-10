
#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Map.h"
#include "Player.h"

#define WINDOWS 1

class Game {
public:
	Game();
	void init();
	void loop();

private:

	Map map; 		// current map
	Player player; 	// current player
    bool run{true};

	void update();
	void draw();

};

#endif /* GAME_H_ */

