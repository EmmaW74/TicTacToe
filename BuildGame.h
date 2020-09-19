#pragma once
#include "Render.h"
#include "Input.h"
#include "I_Player.h"
#include "UserPlayer.h"
#include "AIPlayer.h"
#include "Controller.h"

class BuildGame
{
	int no_of_players = 0;
	std::shared_ptr<Render> render_object{};
	std::shared_ptr<Input> input_object{};
	std::shared_ptr<I_Player> player1;
	std::shared_ptr<I_Player> player2;

public:
	BuildGame();
	int get_no_of_players();
	void create_game();
	void start_game();

	~BuildGame();
};

