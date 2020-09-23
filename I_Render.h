#pragma once
#include <Grid.h>
#include <Player.h>
#include <string>

class I_Render
{

public:
	I_Render();
	virtual ~I_Render() = 0;
	virtual void print_header() = 0;
	virtual void print_grid(Grid& game_board) = 0;
	virtual void request_cell(std::string name) = 0;
	virtual char showXorO(int X_or_O) = 0;
	virtual void congrats(std::string name) = 0;
	virtual void playing(std::string name);
	virtual void draw() = 0;

};

