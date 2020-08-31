#ifndef RENDER_H
#define RENDER_H
#include <Grid.h>
#include <Player.h>
class Render
{
public:
	Render();
	~Render();
	void print_header();
	void print_grid(Grid& game_board);
	std::string request_name(Player* player);
	int number_of_players();
	void get_cell(Player* player, Grid& grid);
	char showXorO(int X_or_O);
	void congrats(Player* player);
	void playing(Player* player);
	void draw();
};




#endif // RENDER_H
