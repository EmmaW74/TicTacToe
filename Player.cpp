#include<iostream>
#include <Controller.h>
#include <Grid.h>
#include <Render.h>
#include <Player.h>

Player::Player() :
	name{"Player"}, XorO{NULL}{
}

Player::Player(std::string name, int XorO) :
	name{ name }, XorO{ XorO }{
}

std::string Player::display_name() {
	return name;
}

int Player::get_XorO() {
	return XorO;
}

void Player::update_name(std::string new_name) {
	name = new_name;
}

Player::~Player()
{
}
