#pragma once
#include "I_Input.h"
class Input2P :
	public I_Input
{
public:
	Input2P();
	virtual std::string request_name(std::string name) override;
	virtual void get_cell(int XorO, Grid& grid) override;
	virtual bool play_again() override;
	~Input2P();

};

