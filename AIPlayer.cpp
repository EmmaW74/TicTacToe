#include "AIPlayer.h"
#include "Render.h"
#include "Grid.h"
#include "windows.h"
#include "Token_enum.h"
#include<string>
#include <iostream>

AIPlayer::AIPlayer() :
	name{ "Player" }, XorO{ Token::NONE }{
}

AIPlayer::AIPlayer(std::string name, Token XorO) :
	name{ name }, XorO{ XorO } {
}

void AIPlayer::update_name(std::string new_name) {
	name = new_name;
}

int AIPlayer::get_XorO() const {
	return static_cast<int>(XorO);
}

std::string AIPlayer::display_name() const {
	return name;
}

void AIPlayer::take_turn(Grid &game_board, std::shared_ptr <I_Input> &input_object, std::shared_ptr <I_Render> &render_object) {
	//Computer takes a random turn
	render_object->playing(name);
	Sleep(3000);
	game_board.random_turn(1);
}
