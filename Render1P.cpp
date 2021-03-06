#include "Render1P.h"
#include<iostream>


Render1P::Render1P() {

};

void Render1P::playing(std::string name) {
	std::cout << name << " is taking their turn..." << std::endl;
};

vvoid playing(std::string name) override;
void Render1P::print_header() {

	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  *   TIC TAC TOE  *" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
}

void Render1P::print_grid(Grid& game_board) {
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
void Render1P::playing(std::string name) {
	std::cout << name << " is taking their turn..." << std::endl;
}

std::string Render1P::request_name(std::shared_ptr<I_Player> player) {
	//Prompt for and return player name
	std::cout << player->display_name() << " - Enter your name" << std::endl;
	std::string name{};
	std::getline(std::cin, name);

	return name;
}

void Render1P::request_cell(std::string name) {
	//requests a cell 	
	std::cout << name << ", please enter a blank cell, for example, A1: ";

}

char Render1P::showXorO(int X_or_O) {
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

void Render1P::congrats(std::string name) {
	std::cout << "Congratulations " << name << std::endl;
	std::cout << "You win!!" << std::endl;
}

void Render1P::draw() {
	std::cout << "It's a draw!!" << std::endl;
}

bool Render1P::play_again() {
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
};

Render1P::~Render1P()
{
};

