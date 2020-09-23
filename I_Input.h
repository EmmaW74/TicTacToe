#pragma once
#include "Grid.h"

class I_Input
{

public:
	I_Input();
	virtual std::string request_name(std::string name) = 0;
	virtual std::string random_name(std::string name);
	virtual void get_cell(int XorO, Grid& grid) = 0;
	virtual bool play_again() = 0;
	~I_Input();
};

