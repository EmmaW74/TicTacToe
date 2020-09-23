#pragma once
#include "I_Input.h"
#include "Grid.h"
#include <memory>

class Input :
	public I_Input

{
	//friend class UserPlayer;
	//friend class AIPlayer;

public:
	Input();
	virtual std::string request_name(std::string name) override;
	//int number_of_players();
	virtual void get_cell(int XorO, Grid& grid) override;
	virtual bool play_again() override;
	~Input();
};

