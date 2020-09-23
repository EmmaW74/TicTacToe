#include "I_Player.h"
#include <iostream>

I_Player::I_Player() :
	name{"Player"}, XorO{0} {
}

I_Player::I_Player(std::string name, int XorO) :
	name{ name }, XorO{ XorO } {
}

I_Player::~I_Player() {
}