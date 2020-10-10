#pragma once
#include "I_Input.h"
#include "Grid.h"
#include "Token_enum.h"
#include <memory>

class Input :
	public I_Input

{

public:
	Input();
	virtual std::string request_name(std::string name) const override;
	virtual std::string random_name(std::string name) const override;
	virtual void get_cell(Token XorO, Grid& grid) override;
	virtual bool play_again() const override;
	~Input() = default;
};

