#pragma once
#include "I_Player.h"
#include "Token_enum.h"


class BasePlayer :
	public I_Player
{
private:
	
public:
	BasePlayer();
	virtual std::string display_name() const = 0;
	virtual int get_XorO() const = 0;
	virtual void update_name(const std::string &new_name) = 0;
	virtual void take_turn(Grid &game_board, const std::shared_ptr <I_Input> &input_object, const std::shared_ptr <I_Render> &render_object) = 0;
	~BasePlayer() = default;
};

