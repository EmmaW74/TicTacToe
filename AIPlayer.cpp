#include "AIPlayer.h"
#include "Render.h"
#include "Grid.h"
#include "windows.h"
#include<string>
#include <iostream>

AIPlayer::AIPlayer() :
	name{ "Player" }, XorO{ 0 }{
}

AIPlayer::AIPlayer(std::string name, int XorO) :
	name{ name }, XorO{ XorO } {
}

void AIPlayer::update_name(std::string new_name) {
	name = new_name;
}

int AIPlayer::get_XorO() {
	return XorO;
}

std::string AIPlayer::display_name() {
	return name;
}

void AIPlayer::take_turn(Grid& game_board, std::shared_ptr <I_Input> input_object, std::shared_ptr <I_Render> render_object) {
	//Computer takes a random turn
	render_object->playing(name);
	Sleep(3000);
	game_board.random_turn(1);
}

AIPlayer::~AIPlayer() {
}