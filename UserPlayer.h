#pragma once

#include "I_Player.h"
#include<string>


class UserPlayer :
	public I_Player
{
	std::string name;
	int XorO;

public:
	UserPlayer();
	UserPlayer(std::string name, int XorO);
	int get_XorO() override;
	std::string display_name() override;
	virtual void update_name(std::string new_name) override;
	virtual void take_turn(Grid& game_board, Input& input_object, Render& render_object) override;
	
	~UserPlayer();
};
