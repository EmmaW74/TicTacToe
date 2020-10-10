#pragma once
#include "I_Player.h"
#include "Token_enum.h"
class BasePlayer :
	public I_Player
{
	std::string name;
	Token XorO;

public:
	BasePlayer();
	BasePlayer(std::string name, Token XorO);
	virtual std::string display_name() const = 0;
	virtual int get_XorO() const = 0;
	virtual void update_name(std::string new_name) = 0;
	virtual void take_turn(Grid &game_board, std::shared_ptr <I_Input> &input_object, std::shared_ptr <I_Render> &render_object) = 0;
	~BasePlayer() = default;
};

