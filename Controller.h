#ifndef CONTROLLER_H
#define CONTROLLER_H
#include "Grid.h"
#include "Render.h"
#include "Input.h"
#include "Player.h"
#include "I_Player.h"

class Controller
{
	bool player1_turn = true;
	bool is_game_won = false;
	Grid game_board{};
	Render render_object{};
	Input input_object{};
	int turns_taken = 0;
	int max_turns = 9;
	int player_number = 0;
public:
	
	Controller();
	~Controller();

	void start_game();
	void play_game(std::shared_ptr<I_Player> player1, std::shared_ptr<I_Player> player2);
	void take_a_turn(Player* player);
	void take_a_random_turn(Player* player);
	void update_turns_taken();
	void set_player_number(int number);
	bool play_again_check();
};

#endif // CONTROLLER_H
