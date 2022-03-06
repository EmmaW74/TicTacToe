#pragma once
#include "Render.h"
#include "Input.h"
#include "I_Player.h"
#include "UserPlayer.h"
#include "AIPlayer.h"
#include "Controller.h"

//Builds a game object with the required players plus rendering and input objects
class BuildGame
{
private:
	int no_of_players = 0;
	std::shared_ptr<I_Render> new_render_object{};
	std::shared_ptr<I_Input> new_input_object{};
	std::shared_ptr<I_Player> player1;
	std::shared_ptr<I_Player> player2;

public:
	BuildGame();
	void print_header1() const;
	int get_no_of_players() const;
	void create_game();
	void start_game();
	~BuildGame() = default;
};

