#include "Game.h"

Game::Game() {

	player = Player("Krock", 2, 2);
	map = Map(player.get_position());

}

void Game::init() {

}


void Game::loop() {

}
