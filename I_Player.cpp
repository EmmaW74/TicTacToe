#include "I_Player.h"
#include <iostream>

I_Player::I_Player() :
	name{"Player"}, XorO{0} {};
I_Player::I_Player(std::string name, int XorO) :
	name{ name }, XorO{ XorO } {};

std::string I_Player::display_name() {
	return name;
}

int I_Player::get_XorO() {
	return XorO;
}

void I_Player::update_name(std::string new_name) {
	name = new_name;
}


I_Player::~I_Player() {};