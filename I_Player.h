#pragma once

#include "Input.h"
#include "Grid.h"
#include "Render.h"

#include<string>
#include<iostream>

//Virtual class to set out the methods that each player type must implement
class I_Player
{

public:
	
	virtual std::string display_name() const = 0;
	virtual int get_XorO() const = 0;
	virtual void update_name(const std::string &new_name) = 0;
	virtual void take_turn(Grid &game_board, const std::shared_ptr <I_Input> &input_object, const std::shared_ptr <I_Render> &render_object) = 0;
	virtual ~I_Player() =0;
};

