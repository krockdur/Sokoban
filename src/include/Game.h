
#ifndef GAME_H_
#define GAME_H_

#include "Map.h"
#include "Player.h"

class Game {
public:
	Game();
	void init();
	void loop();

private:

	Map map; 		// current map
	Player player; 	// current player

};

#endif /* GAME_H_ */

