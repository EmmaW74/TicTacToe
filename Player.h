#pragma once
#include<string>

class Player
{
	std::string name;
	int XorO;
public:
	Player();
	Player(std::string name, int XorO);
	std::string display_name();
	int get_XorO();
	void update_name(std::string new_name);
	~Player();

};

