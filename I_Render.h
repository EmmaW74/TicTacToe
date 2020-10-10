#pragma once
#include "Grid.h"
#include <string>

class I_Render
{

public:
	I_Render();
	virtual ~I_Render() = 0;
	virtual void print_header() const = 0;
	virtual void print_grid(Grid& game_board) const = 0;
	virtual void request_cell(std::string name) const = 0;
	virtual char showXorO(int X_or_O) const = 0;
	virtual void congrats(std::string name) const = 0;
	virtual void playing(std::string name) const;
	virtual void draw() const = 0;

};

