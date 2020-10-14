#pragma once
#include <Token_enum.h>
#include <vector>
#include <string>


class Grid
{
private:
	std::vector<std::pair<std::string, int>> grid_vec{};
public:
		
	std::vector<std::pair<std::string, int>> get_grid() const;
	void reset_grid();
	bool update_grid(const Token &XorO, const std::string &turn);
	bool check_for_win(const int X_or_O) const;
	int check_grid(const std::string &turn);
	~Grid() = default;
};

