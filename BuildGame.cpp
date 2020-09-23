#include "BuildGame.h"
#include <regex>
#include <iomanip>

BuildGame::BuildGame() {
}

int BuildGame::get_no_of_players() {
	//Prompt for number of players (1 or 2)
	print_header1();
	std::cout << "Enter how many players:" << std::endl;
	std::cout << "1 - Play against the computer" << std::endl;
	std::cout << "2 - Play against a friend" << std::endl;

	//Get number of players
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

void BuildGame::print_header1() {
	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  *   TIC TAC TOE  *" << std::endl << std::endl;
	std::cout << std::setw(16) << " " << "  ******************" << std::endl << std::endl;
}

void BuildGame::create_game() {

	no_of_players = get_no_of_players();
	if (no_of_players == 2) {
		//initialise objects for 2 player game
		render_object = std::make_shared<Render2P>();
		input_object = std::make_shared<Input2P>();
		player1 = std::make_shared<UserPlayer>("Player 1", -1);
		player2 = std::make_shared<UserPlayer>("Player 2", 1);
	}
	else {
		//initialise objects for 1 player game
		render_object = std::make_shared<Render>();
		input_object = std::make_shared<Input>();
		player1 = std::make_shared<UserPlayer>("Player 1", -1);
		player2 = std::make_shared<AIPlayer>("Player 2", 1);
	}
	start_game();
}

void BuildGame::start_game() {
	//Build new Controller object with pointers to player, render and input objects
	Controller new_game{ render_object,input_object,player1,player2,no_of_players }; 
	new_game.start_game(); 
}

BuildGame::~BuildGame() {
}
