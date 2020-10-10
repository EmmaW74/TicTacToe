#include "UserPlayer.h"
#include "Input.h"
#include "Token_enum.h"
#include<string>
#include <iostream>

UserPlayer::UserPlayer():
	name{ "Player" }, XorO{ Token::NONE }{}

UserPlayer::UserPlayer(std::string name, Token XorO) :
	name{name}, XorO{ XorO } {}

void UserPlayer::update_name(std::string new_name) {
	name = new_name;
}

int UserPlayer::get_XorO() const {
	return static_cast<int>(XorO);
}

std::string UserPlayer::display_name() const {
	return name;
}

void UserPlayer::take_turn(Grid &game_board, std::shared_ptr <I_Input> &input_object, std::shared_ptr <I_Render> &render_object) {
	
	render_object->request_cell(name);
	input_object->get_cell(XorO, game_board);

}

//UserPlayer::~UserPlayer() {}