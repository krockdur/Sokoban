#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Config.h"
#include "Map.h"
#include "Player.h"

#include <SFML/Graphics.hpp>
//#include <SFML/Window.hpp>

#define WINDOWS 0
#define LINUX 1

#define TIME_BETWEEN_FRAME 30

class Game {
public:
	Game();
	void init();
	void loop();

private:

	Map map; 		// current map
	Player player; 	// current player
    bool run{true};

    sf::Clock Clock;

	void update();
	void draw();

	void debug(Context contexte);

};

#endif /* GAME_H_ */
