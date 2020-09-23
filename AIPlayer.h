#pragma once
#include "I_Player.h"
#include "I_Input.h"
#include<string>
class AIPlayer :
	public I_Player
{
	std::string name;
	int XorO;

public:
	AIPlayer();
	AIPlayer(std::string name, int XorO);
	int  get_XorO() override;
	std::string display_name() override;
	virtual void update_name(std::string new_name) override;
	virtual void take_turn (Grid& game_board, std::shared_ptr <I_Input> input_object, std::shared_ptr <I_Render> render_object) override;
	~AIPlayer();
};

