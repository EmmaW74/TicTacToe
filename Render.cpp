#include "Render.h"
#include "Grid.h"
#include "Controller.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <regex>
#include <iomanip>
#include <limits>
#include <istream>

Render::Render() {

}


std::string Render::request_name(Player* player) {
	//Prompt for and return player name
	std::cout << player->display_name() << " - Enter your name" << std::endl;
	std::string name{};
	std::getline(std::cin, name);

	return name;
}


int Render::number_of_players() {
	//Prompt for and return number of players (1 or 2)
	std::string number{};
	int valid = 0;
	std::cout << "Enter how many players:" << std::endl;
	std::cout << "1 - Play against the computer" << std::endl;
	std::cout << "2 - Play against a friend" << std::endl;

	do {
		std::cin >> number;
		std::regex check("[12]");

		if (std::regex_match(number, check)) {
			valid = 1;
		}
		else {
			std::cout << "Please enter 1 or 2: " << std::endl;
		}
	} while (valid == 0);

	std::string flush{}; // To clear cin before request_name called 
	std::getline(std::cin, flush); // To clear cin before request_name called 
	return std::stoi(number);
}


void Render::get_cell(Player* player, Grid& grid) {
	//requests a cell and updates the grid
	int valid = 0;
	std::cout << player->display_name() << ", please enter a blank cell, for example, A1: ";
	do {
		std::string input;
		std::cin >> input;
		std::string turn = input.substr(0, 2);
		turn.at(0) = static_cast<char>(toupper(turn.at(0)));
		std::regex check("[ABC][123]");

		if (std::regex_match(turn, check)) {
			if (grid.update_grid(player->XorO, turn)) {
				valid = 1;
			}
			else {
				std::cout << "Please enter a blank cell: " << std::endl;
			}
		}
		else {
			std::cout << "Please enter a valid cell, for example, A1: " << std::endl;
		}
	} while (valid == 0);
}

char Render::showXorO(int X_or_O) {
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

void Render::print_header() {

	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  *   TIC TAC TOE  *" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
}

void Render::print_grid(Grid& game_board) {
	//clear screen and draw latest grid state
	system("cls");
	print_header();
	auto it = game_board.grid_vec.begin();

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

void Render::congrats(Player* player) {
	std::cout << "Congratulations " << player->display_name() << std::endl;
	std::cout << "You win!!" << std::endl;
}

void Render::playing(Player* player) {
	std::cout << player->display_name() << " is taking their turn..." << std::endl;
}

void Render::draw() {
	std::cout << "It's a draw!!" << std::endl;
}

Render::~Render()
{
}

