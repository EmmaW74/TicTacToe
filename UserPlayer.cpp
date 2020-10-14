#include "UserPlayer.h"
#include "Input.h"
#include "Token_enum.h"
#include<string>
#include <iostream>


UserPlayer::UserPlayer(const std::string &name, const Token &XorO) :
	name{name}, XorO{ XorO } {}

void UserPlayer::update_name(const std::string &new_name) {
	name = new_name;
}

int UserPlayer::get_XorO() const {
	return static_cast<int>(XorO);
}

std::string UserPlayer::display_name() const {
	return name;
}

void UserPlayer::take_turn(Grid& game_board, const std::shared_ptr <I_Input>& input_object, const std::shared_ptr <I_Render>& render_object) {
	//calls methods to request cell, validate cell and update grid
	render_object->request_cell(name);
	int turn_complete = 0;
	do {
		std::string turn = input_object->get_cell();
		int valid = game_board.check_grid(turn);
		if (valid == 0) {
			if (game_board.update_grid(XorO, turn)) {
				turn_complete++;
			}
			else {
				render_object->something_went_wrong();
			}
		}
		else if (valid == 1) {
			render_object->cell_taken();
		}
		else if (valid == 2) {
			render_object->cell_invalid();
		}
	}
	while (turn_complete == 0);

}