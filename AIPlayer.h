#pragma once
#include "BasePlayer.h"
#include "I_Input.h"
#include "Token_enum.h"
#include<string>
class AIPlayer :
	public BasePlayer
{
	std::string name;
	Token XorO;

public:
	AIPlayer();
	AIPlayer(std::string name, Token XorO);
	int get_XorO() const override;
	std::string display_name() const override;
	virtual void update_name(std::string new_name) override;
	virtual void take_turn (Grid &game_board, std::shared_ptr <I_Input> &input_object, std::shared_ptr <I_Render> &render_object) override;
	~AIPlayer() = default;
};

