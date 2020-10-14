#include "Input.h"
#include <iostream>
#include <regex>
#include "Windows.h"
#include "Token_enum.h"

Input::Input() {
}

std::string Input::request_name(const std::string &name) const {
	//Prompt for and return player name
	std::cout << name << " - Enter your name" << std::endl;
	std::string new_name{};
	std::getline(std::cin, new_name);
	return new_name;
}

std::string Input::random_name(const std::string &name) const {
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


std::string Input::get_cell() const {
	//Get cell input and return it
	std::string input;
	std::cin >> input;
	std::string turn = input.substr(0, 2);
	turn.at(0) = static_cast<char>(toupper(turn.at(0)));
	return turn;
}

bool Input::play_again() const {
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


