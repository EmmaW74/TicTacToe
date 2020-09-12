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
	virtual void take_turn() override;
	~UserPlayer();
};
