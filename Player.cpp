#include<iostream>
#include <Controller.h>
#include <Grid.h>
#include <Render.h>
#include <Player.h>

Player::Player()
{
}

Player::Player(std::string name, int XorO) :
	name{ name }, XorO{ XorO }{
	//    std::cout << "Player 2 arg constructor" << std::endl;
}
std::string Player::display_name() {
	return name;
}

void Player::update_name(std::string new_name) {
	name = new_name;
}

Player::~Player()
{
}

