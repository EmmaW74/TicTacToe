#include "Input.h"
#include <iostream>
#include <regex>
#include "Windows.h"

Input::Input() {
}

std::string Input::request_name(std::string name) {
	//Prompt for and return player name
	std::cout << name << " - Enter your name" << std::endl;
	std::string new_name{};
	std::getline(std::cin, new_name);
	return new_name;
}

std::string Input::random_name(std::string name) {
	//Generate random name and check it's different to Player 1's name
	std::string new_name{ name };
	std::vector<std::string> name_list{ "Fred","James","Harry","George","Henry","Lucy","Jane","Jill","Joanne","Clare" };
	srand(time(0));
	do {
		new_name = name_list.at(rand() % 10);
	} while (new_name == name);

	std::cout << "Today you're playing against " << new_name << std::endl;
	Sleep(3000);
	return new_name;
}

void Input::get_cell(int XorO, Grid& grid) {
	//Gets cell and updates the grid
	int valid = 0;
	do {
		std::string input;
		std::cin >> input;
		std::string turn = input.substr(0, 2);
		turn.at(0) = static_cast<char>(toupper(turn.at(0)));
		std::regex check("[ABC][123]");

		if (std::regex_match(turn, check)) {
			if (grid.update_grid(XorO, turn)) {
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

Input::~Input() {
}
