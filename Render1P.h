#pragma once
#include "I_Render.h"
#include "I_Player.h"
#include "Grid.h"
#include <iomanip>
#include <iostream>
#include <memory>

class Render1P :
	public I_Render
{

public:
	Render1P();
	~Render1P();

	void print_header();
	void print_grid(Grid& game_board);
	std::string request_name(std::shared_ptr<I_Player> player);
	virtual void playing(std::string name) = 0;
	void request_cell(std::string name);
	char showXorO(int X_or_O);
	void congrats(std::string name);
	void draw();
	bool play_again();

	

