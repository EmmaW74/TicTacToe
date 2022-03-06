#include<iostream>
#include "I_Player.h"
#include "AIPlayer.h"
#include "UserPlayer.h"
#include "Render.h"
#include "Input.h"
#include "Controller.h"
#include "Input.h"
#include "windows.h"
#include <vector>
#include <memory>

Controller::Controller() {};

Controller::Controller(const std::shared_ptr<I_Render> &render_object, const std::shared_ptr<I_Input> &input_object, const std::shared_ptr<I_Player> &player1, const std::shared_ptr<I_Player> &player2, const int player_number):
render_object(render_object),input_object(input_object),player1(player1),player2(player2), player_number(player_number){
}

void Controller::start_game(){
	// Get player names
	if (player_number == 2) {
		player1->update_name(input_object->request_name(player1->display_name()));
		player2->update_name(input_object->request_name((*player2).display_name()));
	}
	else {
		player1->update_name(input_object->request_name(player1->display_name()));
		player2->update_name(input_object->random_name(player1->display_name()));
	}

	//Play the game
play_game();
}

void Controller::play_game() {
	//Create and print new grid
	game_board.reset_grid();
	render_object->print_grid(game_board);

	//while game is in progress and max turns not yet taken, check who's turn it is then take the turn for that player
	while (!is_game_won) {
		if (turns_taken >= max_turns) {
			render_object->draw();
			play_again_check();
		}
		else if (player1_turn) {
			(*player1).take_turn(game_board, input_object, render_object);
		}
		else {
			(*player2).take_turn(game_board, input_object, render_object); //If 2 player game - player 2 prompted to play
		}
		update_turns_taken();
		player1_turn = !player1_turn;
		render_object->print_grid(game_board);
		if (game_board.check_for_win(player1->get_XorO())) {
			is_game_won = true;
			render_object->congrats(player1->display_name());
			if (play_again_check()) {
				play_game();
			};
		}
		else if (game_board.check_for_win(player2->get_XorO())) {
			is_game_won = true;
			render_object->congrats(player2->display_name());
			if (play_again_check()) {
				//play_game(player1, player2);
				play_game();
			}
		}
	}
}

void Controller::update_turns_taken() {
	//counts number of turns taken so far
	turns_taken++;
}

bool Controller::play_again_check() {
	if (input_object->play_again()) {
		is_game_won = false;
		turns_taken = 0;
		player1_turn = true;
		player_number = 0;
		//start_game();
		return true;
	}
	else {
		return false;
	}
}
