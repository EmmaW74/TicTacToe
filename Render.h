#pragma once
#include "I_Render.h"
#include "Grid.h"

class Render :
	public I_Render
{
	
public:
	Render();
	virtual void print_header() const override;
	virtual void print_grid(Grid& game_board) const override;
	virtual void request_cell(std::string name) const override;
	virtual char showXorO(int X_or_O) const override;
	virtual void congrats(std::string name) const override;
	virtual void playing(std::string name) const override;
	virtual void draw() const override;
	~Render() = default;
};

