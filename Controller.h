#pragma once
#include "Grid.h"
#include "Render.h"
#include "Input.h"
#include "I_Player.h"

class Controller
{
	bool player1_turn = true;
	bool is_game_won = false;
	Grid game_board{};
	std::shared_ptr<I_Render> render_object;
	std::shared_ptr<I_Input> input_object;
	std::shared_ptr<I_Player> player1;
	std::shared_ptr<I_Player> player2;
	int turns_taken = 0;
	int max_turns = 9;
	int player_number = 0;
public:
	
	Controller();
	Controller(std::shared_ptr<I_Render> &render_object, std::shared_ptr<I_Input> &input_object, std::shared_ptr<I_Player> &player1, std::shared_ptr<I_Player> &player2,int player_number);
	~Controller() = default;
	void start_game();
	void play_game();
	void update_turns_taken();
	bool play_again_check();
};

