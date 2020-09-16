#ifndef RENDER_H
#define RENDER_H
#include <Grid.h>
#include <Player.h>
class Render
{
	friend class UserPlayer;
	friend class AIPlayer;

public:
	Render();
	~Render();
	void print_header();
	void print_grid(Grid& game_board);
	std::string request_name(Player* player);
	void number_of_players();
	void request_cell(std::string name);
	char showXorO(int X_or_O);
	void congrats(std::string name);
	void playing(std::string name);
	void draw();
	bool play_again();
};




#endif // RENDER_H
