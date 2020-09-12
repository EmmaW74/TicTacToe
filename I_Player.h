#pragma once

#include<string>
#include<iostream>

class I_Player
{
	std::string name;
	int XorO;

public:
	I_Player();
	I_Player(std::string name, int XorO);
	std::string display_name();
	int get_XorO();
	void update_name(std::string new_name);
	virtual void take_turn() = 0;
	virtual ~I_Player() =0;
};

