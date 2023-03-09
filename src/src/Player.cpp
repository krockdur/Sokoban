#include "Player.h"

Player::Player(std::string name, int x, int y) {
	this->x = x;
	this->y = y;
	this->name = name;
}

Player::~Player() {
}

Case Player::get_position() {
	Case c(x, y, '@');
	return c;
}
