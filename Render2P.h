#pragma once
#include "I_Render.h"
#include "Grid.h"
class Render2P :
	public I_Render
{

public:
	Render2P();
	virtual void print_header() override;
	virtual void print_grid(Grid& game_board) override;
	virtual void request_cell(std::string name) override;
	virtual char showXorO(int X_or_O) override;
	virtual void congrats(std::string name) override;
	virtual void playing(std::string name) override;
	virtual void draw() override;
	~Render2P() = default;
};

