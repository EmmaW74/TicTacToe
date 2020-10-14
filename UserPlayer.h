#pragma once

#include "BasePlayer.h"
#include "Token_enum.h"
#include<string>


class UserPlayer :
	public BasePlayer
{
private:
	std::string name;
	Token XorO;

public:
	
	UserPlayer(const std::string &name, const Token &XorO);
	int get_XorO() const override;
	std::string display_name() const override;
	virtual void update_name(const std::string &new_name) override;
	virtual void take_turn(Grid &game_board, const std::shared_ptr <I_Input> &input_object, const std::shared_ptr <I_Render> &render_object) override;
	~UserPlayer() = default;
};
