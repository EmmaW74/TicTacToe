#include "Render.h"
#include "Grid.h"
#include "Controller.h"
#include <iostream>
#include <stdlib.h>
#include <regex>
#include <iomanip>
#include <limits>
#include <istream>

Render::Render() {

}

void Render::request_cell(const std::string& name) const {
	//requests a cell 	
	std::cout << name << ", please enter a blank cell, for example, A1: ";
}

void Render::cell_taken() const {
	//advises cell is taken 	
	std::cout << "That cell is taken, please enter a blank cell: ";
}

void Render::cell_invalid() const {
	//advises cell is invalid 	
	std::cout << "That is not a valid cell. Please try again: ";
}

void Render::something_went_wrong() const {
	//error if grid didn't update 	
	std::cout << "Oops something went wrong. Please try again: ";
}

char Render::showXorO(const int X_or_O) const {
	//Display array value as X, O or blank (for grid display)
	if (X_or_O == -1) {
		return 'X';
	}
	else if (X_or_O == 1) {
		return 'O';
	}
	else {
		return ' ';
	}
}

void Render::print_header() const {

	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  *   TIC TAC TOE  *" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
}

void Render::print_grid(const Grid& game_board) const {
	//clear screen and draw latest grid state
	system("cls");
	print_header();
	auto temp = game_board.get_grid();
	auto it = temp.begin();

	//header row
	std::cout << std::setw(12) << " ";
	for (int j = 1; j < 4; j++) {
		std::cout << std::setw(8) << j;
	}
	std::cout << std::endl;
	std::cout << std::setw(16) << " " << std::setw(24) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;

	// other rows
	//for each letter
	for (size_t x = 65; x < 68; x++) {
		//empty row 
		std::cout << std::setw(8) << " ";
		for (size_t j = 0; j < 4; j++) {
			std::cout << std::setw(4) << " " << "   |";
		}
		std::cout << std::endl;
		// row with letter and X's
		std::cout << std::setw(8) << " ";
		std::cout << std::setw(4) << (char)x << "   |";
		for (size_t j = 0; j < 3; j++) {
			std::cout << std::setw(4) << showXorO(it->second) << "   |";
			it++;
		}
		std::cout << std::endl;

		//empty row
		std::cout << std::setw(8) << " ";
		for (size_t j = 0; j < 4; j++) {
			std::cout << std::setw(4) << " " << "   |";
		}

		std::cout << std::endl;
		std::cout << std::setw(16) << " " << std::setw(24) << std::setfill('-') << "-" << std::setfill(' ') << std::endl;
	}
}

void Render::congrats(const std::string& name) const {
	std::cout << "Congratulations " << name << std::endl;
	std::cout << "You win!!" << std::endl;
}

void Render::playing(const std::string& name) const {
	std::cout << name << " is taking their turn..." << std::endl;
}

void Render::draw() const {
	std::cout << "It's a draw!!" << std::endl;
}




