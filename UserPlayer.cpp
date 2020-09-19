
#include "UserPlayer.h"
#include "Input.h"
#include<string>
#include <iostream>

UserPlayer::UserPlayer():
	name{ "Player" }, XorO{ 0 }{
};

UserPlayer::UserPlayer(std::string name, int XorO) :
	name{name}, XorO{ XorO } {};

void UserPlayer::update_name(std::string new_name) {
	name = new_name;
};

int UserPlayer::get_XorO() {
	return XorO;
}

std::string UserPlayer::display_name() {
	return name;
}

void UserPlayer::take_turn(Grid& game_board, std::shared_ptr <Input> input_object, std::shared_ptr <Render> render_object) {
	
	render_object->request_cell(name);
	input_object->get_cell(XorO, game_board);

};



UserPlayer::~UserPlayer() {

};

