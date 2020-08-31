#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <Grid.h>
#include <Render.h>
#include <Player.h>

class Controller : public Render
{
	bool player1_turn = true;
	bool is_game_won = false;
	Grid game_board;
	int turns_taken = 0;
	int max_turns = 9;
	int player_number = 0;
public:
	Controller();
	~Controller();

	void start_game();
	void play_game(Player*, Player*);
	void take_a_turn(Player* player);
	void take_a_random_turn(Player* player);
	void update_turns_taken();
	void set_player_number(int number);
};

#endif // CONTROLLER_H
