#ifndef GRID_H
#define GRID_H
#include <vector>
#include <string>


class Grid
{
	//    constexpr int def_size = 3;
public:
	std::vector<std::pair<std::string, int>> grid_vec{};

	//char grid_array[3][3];
	~Grid();

	void reset_grid();
	bool update_grid(int X_or_O, std::string turn);
	bool check_for_win(int X_or_O);
	void random_turn(int X_or_O);

};

#endif // GRID_H
