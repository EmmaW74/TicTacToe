#pragma once
#include "I_Render.h"
#include <Grid.h>
#include <Player.h>
class Render2P :
	public I_Render
{
	friend class UserPlayer;
	friend class AIPlayer;

public:
	Render2P();

	virtual void print_header() override;
	virtual void print_grid(Grid& game_board) override;
	//virtual std::string request_name(Player* player) override;
	//virtual void number_of_players() override;
	virtual void request_cell(std::string name) override;
	virtual char showXorO(int X_or_O) override;
	virtual void congrats(std::string name) override;
	virtual void playing(std::string name) override;
	virtual void draw() override;
	//virtual bool play_again() override;

	~Render2P();
};

