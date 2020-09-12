
#include "UserPlayer.h"
#include<string>
#include <iostream>

UserPlayer::UserPlayer():
	name{ "Player" }, XorO{ 0 }{
};

UserPlayer::UserPlayer(std::string name, int XorO) :
	name{name}, XorO{ XorO } {};

void UserPlayer::take_turn() {
	
	//take a turn to do
};

UserPlayer::~UserPlayer() {

};

