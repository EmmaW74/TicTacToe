  #include "Controller.h"
#include "Grid.h"
#include "I_Render.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <vector>
#include <string>
#include <regex>

std::vector<std::pair<std::string, int>> Grid::get_grid() const {
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





int Grid::check_grid(const std::string &turn) {
	//Checks if turn is valid - returns 0 for valid, 1 for cell taken, 2 for invalid cell reference
	std::regex check("[ABC][123]");
	if (std::regex_match(turn, check)) {
		for (auto it = grid_vec.begin(); it != grid_vec.end(); ++it)
		{
			if (it->first == turn)
			{
				if (it->second == 0) {
					return 0;
				}
				else {
					return 1;
				}
			}
		}

	}
	else {
		return 2;
	} 
	return 2;
}

bool Grid::update_grid(const Token &XorO, const std::string &turn) {
	//Updates grid with X or O and returns true if successful
	for (auto it = grid_vec.begin(); it != grid_vec.end(); ++it)
	{
		if (it->first == turn)
		{
			it->second = static_cast<int>(XorO);
			return true;
		}
	}
	return false;
}

bool Grid::check_for_win(const int X_or_O) const {
	//Check each row, column and diagonal for a row of 3
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


