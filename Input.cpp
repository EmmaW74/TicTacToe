#include "Input.h"
#include <iostream>
#include <regex>

Input::Input() {};
std::string Input::request_name(Player* player) {
	//Prompt for and return player name
	std::cout << player->display_name() << " - Enter your name" << std::endl;
	std::string name{};
	std::getline(std::cin, name);
	return name;
}

int Input::number_of_players() {
	//Get and return number of players (1 or 2)
	std::string number{};
	int valid = 0;
	
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


void Input::get_cell(Player* player, Grid& grid) {
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
			if (grid.update_grid(player->get_XorO(), turn)) {
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
bool Input::play_again() {
	//Prompt to play another game
	std::cout << "Would you like to play again? Y / N" << std::endl;
	std::string input{};
	std::cin >> input;
	std::string option = input.substr(0, 1);

	std::string flush{}; // To clear cin before game restarts
	std::getline(std::cin, flush); // To clear cin before game restarts

	if (option == "Y" || option == "y") {
		system("cls");
		return true;
	}
	else {
		return false;
	}
}
Input::~Input() {};
