#ifndef PLAYER_H
#define PLAYER_H
#include<string>

class Player
{
	std::string name{};
public:
	int XorO;
	Player();
	Player(std::string name, int XorO);
	std::string display_name();
	void update_name(std::string new_name);
	~Player();

};

#endif // PLAYER_H
