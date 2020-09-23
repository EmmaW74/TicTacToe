#pragma once

#include "Grid.h"

class I_Input
{
	//friend class UserPlayer;
	//friend class AIPlayer;

public:
	I_Input();
	virtual std::string request_name(std::string name) = 0;
	//int number_of_players();
	virtual void get_cell(int XorO, Grid& grid) = 0;
	virtual bool play_again() = 0;
	~I_Input();
};

