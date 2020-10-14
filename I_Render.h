#pragma once
#include "Grid.h"
#include <string>

class I_Render
{

public:
	I_Render();
	virtual ~I_Render() = 0;
	virtual void print_header() const = 0;
	virtual void print_grid(const Grid& game_board) const = 0;
	virtual void request_cell(const std::string &name) const = 0;
	virtual void cell_taken() const = 0;
	virtual void cell_invalid() const = 0;
	virtual void something_went_wrong() const = 0;
	virtual char showXorO(const int X_or_O) const = 0;
	virtual void congrats(const std::string &name) const = 0;
	virtual void playing(const std::string &name) const = 0;
	virtual void draw() const = 0;

};

