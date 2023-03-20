#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Config.h"
#include "Map.h"
#include "Player.h"

#include <SFML/Graphics.hpp>




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

	sf::Texture texture_box, texture_background, texture_obj, texture_player, texture_wall;
	sf::Sprite sprite_bg, sprite_box, sprite_obj, sprite_player, sprite_wall;
	sf::RenderWindow game_window;
	sf::Event event;

	bool run{ true };

	sf::Clock Clock;

	void update();
	void draw();

	void debug(Context contexte);

};

#endif /* GAME_H_ */
