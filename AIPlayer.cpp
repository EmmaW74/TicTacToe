#include "AIPlayer.h"
#include "Render.h"
#include "Grid.h"
#include "windows.h"
#include "Token_enum.h"
#include<string>
#include <iostream>
#include <ctime>

AIPlayer::AIPlayer(std::string name, Token XorO) :
	name{ name }, XorO{ XorO } {
}

void AIPlayer::update_name(const std::string &new_name) {
	name = new_name;
}

int AIPlayer::get_XorO() const {
	return static_cast<int>(XorO);
}

std::string AIPlayer::display_name() const {
	return name;
}

void AIPlayer::take_turn(Grid& game_board, const std::shared_ptr <I_Input>& input_object, const std::shared_ptr <I_Render>& render_object) {
	//calls methods to generate random turn, validate cell and update grid
	render_object->playing(name);
	Sleep(3000);
	int turn_complete = 0;
	do {
		srand(time(0));
		auto it = (game_board.get_grid()).at(rand() % (game_board.get_grid()).size());
		std::string turn = it.first;
		int valid = game_board.check_grid(turn);
		if (valid == 0) {
			if (game_board.update_grid(XorO, turn)) {
				turn_complete++;
			}
		}
	} while (turn_complete == 0);

}
