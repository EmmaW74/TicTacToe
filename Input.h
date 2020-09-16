#pragma once

#include "Grid.h"
#include <memory>

class Input
{
	friend class UserPlayer;
	friend class AIPlayer;

public:
	Input();
	std::string request_name(std::string name);
	int number_of_players();
	void get_cell(int XorO, Grid& grid);
	bool play_again();
	~Input();
};

