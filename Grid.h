#pragma once
#include <vector>
#include <string>


class Grid
{
	std::vector<std::pair<std::string, int>> grid_vec{};
public:
		
	~Grid();
	std::vector<std::pair<std::string, int>> get_grid();
	void reset_grid();
	bool update_grid(int X_or_O, std::string turn);
	bool check_for_win(int X_or_O);
	void random_turn(int X_or_O);

};

