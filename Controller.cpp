#include<iostream>
#include <Controller.h>
#include <Grid.h>
#include <Render.h>
#include <Player.h>
#include <windows.h>


void Controller::set_player_number(int number) {
	//Sets number of players in the game
	player_number = number;
}

void Controller::start_game() {
	//Initial settings for the game
	//Create player objects
	Player* player1 = new Player{ "Player 1",-1 };
	Player* player2 = new Player{ "Player 2",1 };

	//Choose number of players and enter names
	print_header();
	set_player_number(number_of_players());
	//std::cout << "Player 1 - Enter your name" << std::endl;
	player1->update_name(request_name(player1));
	if (player_number == 2) {
		// std::cout << "Player 2 - Enter your name"  << std::endl;
		player2->update_name(request_name(player2));
	}

	//Create and print new grid
	game_board.reset_grid();
	print_grid(game_board);

	//play the game
	play_game(player1, player2);
}

void Controller::play_game(Player* player1, Player* player2) {
	//while game is in progress and max turns not yet taken, check who's turn it is then take the turn for that player
	while (!is_game_won) {
		if (turns_taken >= max_turns) {
			draw();
			break;
		}
		else if (player1_turn) {
			take_a_turn(player1);
		}
		else {
			if (player_number == 2) {
				take_a_turn(player2); //If 2 player game - player 2 prompted to play
			}
			else {
				take_a_random_turn(player2); //If 1 player game - automatic turn taken for player 2
			}
		}
	}

}
void Controller::take_a_random_turn(Player* player) {
	//generates a random turn, refreshes grid and checks if game won yet
	playing(player);
	Sleep(3000);
	game_board.random_turn(1);
	player1_turn = !player1_turn;
	update_turns_taken();
	print_grid(game_board);
	if (game_board.check_for_win(player->XorO)) {
		is_game_won = true;
		congrats(player);
	}
}

void Controller::take_a_turn(Player* player) {
	//controls the player's turn, refreshes grid and checks if game won yet
	get_cell(player, game_board);
	player1_turn = !player1_turn;
	update_turns_taken();
	print_grid(game_board);
	if (game_board.check_for_win(player->XorO)) {
		is_game_won = true;
		congrats(player);
	}
}

void Controller::update_turns_taken() {
	//counts number of turns taken so far
	turns_taken++;
}

Controller::Controller()
{
}

Controller::~Controller()
{
}

