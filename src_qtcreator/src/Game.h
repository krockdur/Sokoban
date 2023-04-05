#ifndef GAME_H_
#define GAME_H_

#include <string>

#include "Config.h"
#include "Map.h"
#include "Player.h"

#include <SFML/Graphics.hpp>




#define WINDOWS 0
#define LINUX 1

#define TIME_BETWEEN_FRAME 60

class Game {

public:
	Game() = default;
	void init();
	void load_lvl(int lvl);
	void update( sf::Time elapsed_time );
	void draw( sf::RenderWindow* game_window );

private:

	Map map; 		// current map
	Player player; 	// current player


	
	sf::Texture texture_box, texture_background, texture_obj, texture_player, texture_wall, texture_player_on_obj, texture_box_on_obj;
	sf::Sprite sprite_bg, sprite_box, sprite_obj, sprite_player, sprite_wall;
	//sf::RenderWindow game_window;
	sf::Event event;

	enum Direction { up, down, left, right, none };
	Direction last_player_direction;


	float pos_player_x{ 0.0f };
	float pos_player_y{ 0.0f };
	Case case_player_destination{ 0, 0, ' ' };

	bool moved{ false };
	bool have_to_move{ false };
	bool load_sprite_error{ false };

	


	void transfert_object(Case start_case, Case next_case, char new_value_start_case, char new_value_next_case);
	void load_textures();
	void create_sprites();
	void debug(Context contexte);

};

#endif /* GAME_H_ */
