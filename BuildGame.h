#pragma once
#include "Render.h"
#include "Render2P.h"
#include "Input.h"
#include "Input2P.h"
#include "I_Player.h"
#include "UserPlayer.h"
#include "AIPlayer.h"
#include "Controller.h"

class BuildGame
{
	int no_of_players = 0;
	std::shared_ptr<I_Render> render_object{};
	std::shared_ptr<I_Input> input_object{};
	std::shared_ptr<I_Player> player1;
	std::shared_ptr<I_Player> player2;

public:
	BuildGame();
	void print_header1();
	int get_no_of_players();
	void create_game();
	void start_game();
	~BuildGame();
};

