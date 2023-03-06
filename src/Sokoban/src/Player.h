/*
 * Player.h
 *
 *  Created on: 6 mars 2023
 *      Author: a430885
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include <iostream>
#include <string>
#include "Map.h"

class Player {

private:
	int current_case_x = 0, current_case_y = 0;

	// Retourne si le d�placement est possible
	bool check_collision(std::string direction);
	// Retourne si le player va entrer en contact avec un objet � d�placer
	int check_movable_object(std::string direction);

	int check_next_case(std::string direction);

	void new_move_player(std::string direction);
	void player_collide_3(std::string direction);
	void player_collide_4(std::string direction);
	void player_collide_5(std::string direction);

public:
	Player(int init_case_x, int init_case_y);

	bool move_player(std::string direction);
	void player_organizer(std::string direction);
};


#endif /* PLAYER_H_ */
