#pragma once
#include "I_Render.h"
#include "Grid.h"

class Render :
	public I_Render
{
	
public:
	Render();
	virtual void print_header() const override;
	virtual void print_grid(const Grid& game_board) const override;
	virtual void request_cell(const std::string &name) const override;
	virtual void cell_taken() const override;
	virtual void cell_invalid() const override;
	virtual void something_went_wrong() const override;
	virtual char showXorO(const int X_or_O) const override;
	virtual void congrats(const std::string& name) const override;
	virtual void playing(const std::string& name) const override;
	virtual void draw() const override;
	~Render() = default;
};

