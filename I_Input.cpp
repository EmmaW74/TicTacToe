#include "I_Input.h"
#include <iostream>
#include <regex>
#include <cstdlib>
#include "Windows.h"

I_Input::I_Input() {
}

std::string I_Input::random_name(std::string name) const {
	//Generate random name and check it's different to Player 1's name
	std::string new_name{name};
	std::vector<std::string> name_list{ "Fred","James","Harry","George","Henry","Lucy","Jane","Jill","Joanne","Clare" };
	srand(time(0));
	do {
		new_name = name_list.at(rand() % 10);
		} while (new_name == name);
	
		std::cout << "Today you're playing against " << new_name << std::endl;
		Sleep(3000);

	return new_name;
}

I_Input::~I_Input() {};
