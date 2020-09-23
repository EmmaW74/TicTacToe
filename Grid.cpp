#include <Controller.h>
#include <Grid.h>
#include <I_Render.h>
#include <Player.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>
#include <string>

std::vector<std::pair<std::string, int>> Grid::get_grid() {
	return grid_vec;
}

void Grid::reset_grid() {
	//Sets all values on the grid to 0
	grid_vec.clear();
	std::string setup{ "" };

	char setup_row{ 'A' };
	char setup_column{ '1' };

	for (size_t i = 0; i < 3; i++) {

		for (size_t i = 0; i < 3; i++) {
			setup = "";
			setup.append(1, setup_row);
			setup.append(1, setup_column);

			grid_vec.emplace_back(setup, 0);
			setup_column++;
		}
		setup_column = '1';
		setup_row++;
	}
}

void Grid::random_turn(int X_or_O) {
	//Generate random row and column values and update that cell with token value (1 or -1)
	int played = 0;
	srand(time(0));

	do {
		auto it = &grid_vec.at(rand() % grid_vec.size());
		std::string random = it->first;

		for (auto it2 = grid_vec.begin(); it2 != grid_vec.end(); ++it2)
		{
			if (it2->first == random) {
				if (it2->second == 0) {
					it->second = X_or_O;
					played++;
				}
			}
		}
	} while (played == 0);
}

bool Grid::update_grid(int X_or_O, std::string turn) {

	for (auto it = grid_vec.begin(); it != grid_vec.end(); ++it)
	{
		if (it->first == turn)
		{
			if (it->second == 0) {
				it->second = X_or_O;
				return true;
			}
			else {
				std::cout << "That cell is taken. ";
				return false;
			}
		}
	}
	return false;
}

bool Grid::check_for_win(int X_or_O) {

	int result = 0;
	auto it = grid_vec.begin();
	//check rows        
	for (size_t x = 0; x < 3; x++) {
		result = 0;
		for (size_t y = 0; y < 3; y++) {
			{
				if (it->second == X_or_O)
				{
					result++;
					it++;
				}
				else {
					it++;
				}
			}
			if (result == 3) {
				return true;
			}
		}
	}
	//Check columns
	int pos = 0;
	for (size_t x = 0; x < 3; x++) {
		result = 0;
		it = grid_vec.begin() + pos;
		for (size_t y = 0; y < 3; y++) {
			if (it->second == X_or_O)
			{
				result++;
				if (it < grid_vec.end() - 2) {
					it = it + 3;
				}
			}
			else {
				if (it < grid_vec.end() - 2) {
				it = it + 3;
			}
			}
		}
		if (result == 3) {
			return true;
		}
		else {
			pos++;
		}
	}

	//Check diagonal from A1
	it = grid_vec.begin();
	result = 0;
	for (size_t x = 0; x < 3; x++) {

		if (it->second == X_or_O)
		{
			result++;
			if (it < grid_vec.end() - 3) {
			it += 4;
		}
		}
		else {
			if (it < grid_vec.end() - 3) {
				it += 4;
			}
		}
		if (result == 3) {
			return true;
		}

	}

	//Check diagonal from A3
	result = 0;
	it = grid_vec.end() - 3;
	for (size_t x = 0; x < 3; x++) {

		if (it->second == X_or_O)
		{
			result++;
			if (it > grid_vec.begin() + 1) {
				it -= 2;
			}
			
		}
		else {
			if (it > grid_vec.begin() + 1) {
				it -= 2;
			}
		}
		if (result == 3) {
			return true;
		}
	}
	   
	return false;
}

Grid::~Grid()
{
}
