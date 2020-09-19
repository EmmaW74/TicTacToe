#pragma once

#include "Input.h"
#include "Grid.h"
#include "Render.h"

#include<string>
#include<iostream>

class I_Player
{
	std::string name;
	int XorO;

public:
	I_Player();
	I_Player(std::string name, int XorO);
	virtual std::string display_name() = 0;
	virtual int get_XorO() = 0;
	virtual void update_name(std::string new_name) = 0;
	virtual void take_turn(Grid& game_board, std::shared_ptr <Input> input_object, std::shared_ptr <Render> render_object) = 0;
	virtual ~I_Player() =0;
};

