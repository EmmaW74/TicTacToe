#pragma once
#include "I_Input.h"
#include "Grid.h"
#include <memory>

class Input :
	public I_Input

{

public:
	Input();
	virtual std::string request_name(std::string name) override;
	virtual std::string random_name(std::string name) override;
	virtual void get_cell(int XorO, Grid& grid) override;
	virtual bool play_again() override;
	~Input();
};

