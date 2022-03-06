#pragma once
#include "BasePlayer.h"
#include "I_Input.h"
#include "Token_enum.h"
#include<string>

//Player type to implement player methods for a computer player
class AIPlayer :
	public BasePlayer
{
private:
	std::string name;
	Token XorO;

public:
	
	AIPlayer(std::string name, Token XorO);
	int get_XorO() const override;
	std::string display_name() const override;
	virtual void update_name(const std::string &new_name) override;
	virtual void take_turn (Grid &game_board, const std::shared_ptr <I_Input> &input_object, const std::shared_ptr <I_Render> &render_object) override;
	~AIPlayer() = default;
};

