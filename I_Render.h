#pragma once
#include <Grid.h>
#include <Player.h>
#include <string>

class I_Render
{
	//friend class UserPlayer;
	//friend class AIPlayer;

public:
	I_Render();
	virtual ~I_Render() = 0;
	virtual void print_header() = 0;
	virtual void print_grid(Grid& game_board) = 0;
	//virtual std::string request_name(Player* player) = 0;
	//virtual void number_of_players() = 0;
	virtual void request_cell(std::string name) = 0;
	virtual char showXorO(int X_or_O) = 0;
	virtual void congrats(std::string name) = 0;
	virtual void playing(std::string name);
	virtual void draw() = 0;
	//virtual bool play_again() = 0;
};

