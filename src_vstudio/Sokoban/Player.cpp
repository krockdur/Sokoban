#include "Player.h"

Player::Player(std::string name, int x, int y) {
	this->x = x;
	this->y = y;
	this->name = name;
	this->value = '@';
}

Player::~Player() {
}

Case Player::get_position() {
	Case c(x, y, value);
	return c;
}

void Player::set_position(Case new_position) {
	this->x = new_position.get_x();
	this->y = new_position.get_y();
	this->value = new_position.get_value();
}

