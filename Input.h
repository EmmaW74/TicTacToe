#pragma once
#include "Player.h"
#include "Grid.h"

class Input
{
public:
	Input();
	std::string request_name(Player* player);
	int number_of_players();
	void get_cell(Player* player, Grid& grid);
	bool play_again();
	~Input();
};

